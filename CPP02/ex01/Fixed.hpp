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
	// copy assignment operator overload
	Fixed &operator=(const Fixed &other);
	~Fixed();

	float	toFloat() const;
	int		toInt() const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif