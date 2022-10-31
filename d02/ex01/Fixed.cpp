/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:07:56 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/31 15:07:35 by lfrederi         ###   ########.fr       */
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

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::Fixed(const int fixed_point) 
	: _fixed_point(fixed_point * 1 << Fixed::_FRACT_BITS)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float fixed_point) 
	: _fixed_point(roundf(fixed_point * (1 << Fixed::_FRACT_BITS))) 
{
	std::cout << "Float constructor called\n";
}

Fixed	&Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called\n";
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
	return (this->_fixed_point / (1 << Fixed::_FRACT_BITS));
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
