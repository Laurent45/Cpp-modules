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
Fixed::Fixed(void) : _fixed_point(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const & copy) : _fixed_point(copy._fixed_point)
{
	std::cout << "Copy constructor called\n";
}

Fixed::Fixed(int const fixed_point) 
	: _fixed_point(fixed_point << Fixed::_FRACT_BITS)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const fixed_point) 
	: _fixed_point(roundf(fixed_point * (1 << Fixed::_FRACT_BITS))) 
{
	std::cout << "Float constructor called\n";
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
		this->_fixed_point = rhs._fixed_point;
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
	return this->_fixed_point;
}

void	Fixed::setRawBits(int const raw)
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

std::ostream &	operator<<(std::ostream & out, Fixed const & fixed) {
	out << fixed.toFloat();
	return out;
}
