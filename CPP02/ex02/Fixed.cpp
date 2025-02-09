#include "Fixed.hpp"
#include <iostream>
#include <climits>
#include <cmath>

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed::Fixed(const int value) {
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
	if (this != &other) {
		this->_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits() const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

float Fixed::toFloat() const {
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _value >> _fractionalBits;

}

bool Fixed::operator>(const Fixed &other) const {
	return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->_value != other._value);
}

Fixed &Fixed::operator++() {
    if (this->getRawBits() == INT_MAX) {
        std::cerr << "Error: Fixed-Point overflow! Value is at maximum." << std::endl;
    } else {
        this->setRawBits(this->getRawBits() + 1);
    }
    return *this;
}

Fixed &Fixed::operator--() {
    if (this->getRawBits() == INT_MIN) {
        std::cerr << "Error: Fixed-Point overflow! Value is at minimum." << std::endl;
    } else {
        this->setRawBits(this->getRawBits() - 1);
    }
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    if (this->getRawBits() == INT_MAX) {
        std::cerr << "Error: Fixed-Point overflow! Value is at maximum." << std::endl;
    } else {
        this->setRawBits(this->getRawBits() + 1);
    }
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    if (this->getRawBits() == INT_MIN) {
        std::cerr << "Error: Fixed-Point overflow! Value is at minimum." << std::endl;
    } else {
        this->setRawBits(this->getRawBits() - 1);
    }
    return temp;
}

Fixed Fixed::operator+(const Fixed &other) const {
    if (this->getRawBits() > INT_MAX - other.getRawBits() || this->getRawBits() < INT_MIN - other.getRawBits()) {
        std::cerr << "Error: Fixed-Point overflow! Cannot summarize." << std::endl;
        return Fixed();
    }
    return Fixed(this->getRawBits() + other.getRawBits());
}

Fixed Fixed::operator-(const Fixed &other) const {
    if (this->getRawBits() > INT_MAX + other.getRawBits() || this->getRawBits() < INT_MIN + other.getRawBits()) {
        std::cerr << "Error: Fixed-Point overflow! Cannot substract." << std::endl;
        return Fixed();
    }
    return Fixed(this->getRawBits() - other.getRawBits());
}

Fixed Fixed::operator*(const Fixed &other) const {
    if (other.getRawBits() == 0)
        return Fixed(0);
    if (other.getRawBits() == -1 && this->getRawBits() == INT_MIN) {
        std::cerr << "Error: Fixed-Point overflow! Cannot multiply." << std::endl;
        return Fixed();
    }
    if (this->getRawBits() > INT_MAX / other.getRawBits() || this->getRawBits() < INT_MIN / other.getRawBits()) {
        std::cerr << "Error: Fixed-Point overflow! Cannot multiply." << std::endl;
        return Fixed();
    }
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other.getRawBits() == 0) {
        std::cerr << "Error: division by zero." << std::endl;
        return Fixed();
    }
    if (other.getRawBits() == -1 && this->getRawBits() == INT_MIN) {
        std::cerr << "Error: Fixed-Point overflow! Cannot divide." << std::endl;
        return Fixed();
    }
    float result = this->toFloat() / other.toFloat();
    if (result > INT_MAX || result < INT_MIN) {
        std::cerr << "Error: Fixed-Point overflow! Cannot divide." << std::endl;
        return Fixed();
    }
    return Fixed(result);
}


Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
    return (f1 > f2) ? f2 : f1;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
    return (f1 > f2) ? f1 : f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
    return (f1 > f2) ? f2 : f1;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
    return (f1 > f2) ? f1 : f2;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
	return out;
}