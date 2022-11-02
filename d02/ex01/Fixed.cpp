/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:07:56 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/02 16:28:05 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*									PUBLIC									  */
/*																			  */
/* ************************************************************************** */

// Canonical form
Fixed::Fixed(void) : _fixedPoint(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const & copy) : _fixedPoint(copy._fixedPoint)
{
	std::cout << "Copy constructor called\n";
}

Fixed::Fixed(int const fixed_point) 
	: _fixedPoint(fixed_point << Fixed::_FRACT_BITS)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const fixed_point) 
	: _fixedPoint(roundf(fixed_point * (1 << Fixed::_FRACT_BITS))) 
{
	std::cout << "Float constructor called\n";
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
		this->_fixedPoint = rhs._fixedPoint;
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

// Members functions
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

std::ostream &	operator<<(std::ostream & out, Fixed const & fixed) {
	out << fixed.toFloat();
	return out;
}
