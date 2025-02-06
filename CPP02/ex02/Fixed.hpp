#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private: 
	int _value;
	static const int _fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int value);
	Fixed(const float value);

	Fixed &operator=(const Fixed &other);
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed &operator++(); // ++x
    Fixed &operator--(); // --x

    Fixed operator++(int); // x++
    Fixed operator--(int); // x--


	~Fixed();

	float				toFloat() const;
	int					toInt() const;
	int					getRawBits( void ) const;
	void				setRawBits( int const raw );

	static Fixed		&min(Fixed &f1, Fixed &f2);
	static Fixed		&max(Fixed &f1, Fixed &f2);
	static const Fixed	&min(const Fixed &f1, const Fixed &f2);
	static const Fixed	&max(const Fixed &f1, const Fixed &f2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif