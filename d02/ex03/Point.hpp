/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:18:18 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/01 13:51:32 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

/* ************************************************************************** */
/*									POINT									  */
/*																			  */
/* ************************************************************************** */

class Point
{

	public:
		
		Point(void);
		Point(float const x, float const y);
		Point(Point const & copy);
		Point &operator=(Point const & rhs);
		~Point(void);

		bool	operator==(Point const & rhs) const;
		float	aire(Point const & a, Point const & b) const;


	private:
		const Fixed _x;
		const Fixed _y;

};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
