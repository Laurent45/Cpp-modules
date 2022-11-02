/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:07:56 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/02 16:28:58 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*									PUBLIC									  */
/*																			  */
/* ************************************************************************** */

/*                       CONSTRUCTORS-DESTRUCTORS                             */

// Canonical form
Fixed::Fixed(void) : _fixedPoint(0)
{
}

Fixed::Fixed(Fixed const & copy) : _fixedPoint(copy._fixedPoint)
{
}

Fixed	&Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_fixedPoint = rhs._fixedPoint;
	return *this;
}

Fixed::~Fixed(void)
{
}

// Constructors
Fixed::Fixed(int const fixed_point) 
	: _fixedPoint(fixed_point << Fixed::_FRACT_BITS)
{
}

Fixed::Fixed(float const fixed_point) 
	: _fixedPoint(roundf(fixed_point * (1 << Fixed::_FRACT_BITS))) 
{
}

 /*								MEMBERS FUNCTIONS							  */
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return this->_fixedPoint;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->_fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->_fixedPoint / (float) (1 << Fixed::_FRACT_BITS));
}

int		Fixed::toInt(void) const
{
	return (roundf(this->toFloat()));
}

// Overloading operators
bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->_fixedPoint > rhs._fixedPoint);
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->_fixedPoint < rhs._fixedPoint);
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_fixedPoint >= rhs._fixedPoint);
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->_fixedPoint <= rhs._fixedPoint);
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->_fixedPoint == rhs._fixedPoint);
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_fixedPoint != rhs._fixedPoint);
}

Fixed	Fixed::operator+(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &	Fixed::operator++(void)
{
	++this->_fixedPoint;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_fixedPoint++;
	return tmp;
}

Fixed &	Fixed::operator--(void)
{
	--this->_fixedPoint;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_fixedPoint--;
	return tmp;
}

// Static members functions
Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&	Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &	Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	& Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return (a);
	return (b);
}

/*							NON-MEMBERS FUCTIONS							  */

std::ostream &	operator<<(std::ostream & out, Fixed const & rhs) {
	out << rhs.toFloat();
	return out;
}
