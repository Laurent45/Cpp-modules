/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:07:56 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/01 07:46:25 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/* ************************************************************************** */
/*									PUBLIC									  */
/*																			  */
/* ************************************************************************** */

/*                       CONSTRUCTORS-DESTRUCTORS                             */

// Canonical form
Fixed::Fixed(void) : _fixed_point(0)
{
}

Fixed::Fixed(Fixed const & copy)
{
	*this = copy;
}

Fixed	&Fixed::operator=(Fixed const & rhs)
{
	this->_fixed_point = rhs._fixed_point;
	return *this;
}

Fixed::~Fixed(void)
{
}

// Constructors
Fixed::Fixed(const int fixed_point) 
	: _fixed_point(fixed_point << Fixed::_FRACT_BITS)
{
}

Fixed::Fixed(const float fixed_point) 
	: _fixed_point(roundf(fixed_point * (1 << Fixed::_FRACT_BITS))) 
{
}

 /*								MEMBERS FUNCTIONS							  */
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return this->_fixed_point;
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called\n";
	this->_fixed_point = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->_fixed_point / (float) (1 << Fixed::_FRACT_BITS));
}

int		Fixed::toInt(void) const
{
	return (roundf(this->toFloat()));
}

// Overloading operators
bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->_fixed_point > rhs._fixed_point);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->_fixed_point < rhs._fixed_point);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_fixed_point >= rhs._fixed_point);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_fixed_point <= rhs._fixed_point);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->_fixed_point == rhs._fixed_point);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_fixed_point != rhs._fixed_point);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	++this->_fixed_point;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_fixed_point++;
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	--this->_fixed_point;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_fixed_point--;
	return tmp;
}

// Static members functions
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

/*							NON-MEMBERS FUCTIONS							  */

std::ostream	&operator<<(std::ostream &out, const Fixed &rhs) {
	out << rhs.toFloat();
	return out;
}
