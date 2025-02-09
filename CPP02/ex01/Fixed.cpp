#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;

    // checking if value can potentially go outside of int limits
    if (value > (1 << (31 - _fractionalBits)) - 1) {
        std::cerr << "Warning: Value too large, clamping to max Fixed-Point value!" << std::endl;
        _value = (1U << 31) - 1;  // setting max value
    } else if (value < -(1 << (31 - _fractionalBits))) {
        std::cerr << "Warning: Value too small, clamping to min Fixed-Point value!" << std::endl;
        _value = -(1U << 31);  // setting min value
    } else {
        _value = value << _fractionalBits;
    }
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;

    float maxFixedValue = (float)((1 << (31 - _fractionalBits)) - 1);
    float minFixedValue = -maxFixedValue;
    float minNonZeroFixed = 1.0f / (1 << _fractionalBits); // 1/256 = 0.00390625

    if (value > maxFixedValue) {
        std::cerr << "Warning: Value too large, clamping to max Fixed-Point value!" << std::endl;
        _value = (1U << 31) - 1;
    } else if (value < minFixedValue) {
        std::cerr << "Warning: Value too small, clamping to min Fixed-Point value!" << std::endl;
        _value = -(1U << 31);
    } else if (value > 0 && value < minNonZeroFixed) {
        std::cerr << "Warning: Too small positive value, clamping to smallest nonzero Fixed-Point!" << std::endl;
        _value = 1;
    } else if (value < 0 && value > -minNonZeroFixed) {
        std::cerr << "Warning: Too small negative value, clamping to smallest negative Fixed-Point!" << std::endl;
        _value = -1;
    } else {
		// when multiplying C++ automatically converts float to int here
        _value = roundf(value * (1 << _fractionalBits));
    }
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

float Fixed::toFloat() const {
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _value >> _fractionalBits;

}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
	return out;
}