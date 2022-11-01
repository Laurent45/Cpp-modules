/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:18:12 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/01 13:50:48 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/*									PUBLIC									  */
/*																			  */
/* ************************************************************************** */

/*                       CONSTRUCTORS-DESTRUCTORS                             */

Point::Point(void) : _x(0), _y(0)
{}

Point::Point(float const x, float const y) : _x(x), _y(y)
{}

Point::Point(Point const & copy) : _x(copy._x), _y(copy._y)
{}

Point &	Point::operator=(Point const & rhs)
{
	(void) rhs;
	std::cout << "Failed to assignement operation, all attributes are const\n";
	return *this;
}

Point::~Point(void)
{}

 /*								MEMBERS FUNCTIONS							  */

bool	Point::operator==(Point const & rhs) const
{
	if (this->_x == rhs._x && this->_y == rhs._y)
		return (true);
	return (false);
}

float	Point::aire(Point const & a, Point const & b) const
{
	float aire = 0;
	aire += (this->_x.toFloat() * (a._y.toFloat() - b._y.toFloat()));
	aire += (a._x.toFloat() * (b._y.toFloat() - this->_y.toFloat()));
	aire += (b._x.toFloat() * (this->_y.toFloat() - a._y.toFloat()));
	aire /= 2.0f;

	if (aire < 0)
		return (-aire);
	return (aire);
}
