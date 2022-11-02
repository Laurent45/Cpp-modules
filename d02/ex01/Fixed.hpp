/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:08:26 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/01 13:23:20 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define FRACT_BITS	8

/* ************************************************************************** */
/*									FIXED									  */
/*																			  */
/* ************************************************************************** */


class Fixed
{

	public:

		Fixed(void);
		Fixed(Fixed const & copy);
		Fixed(int const fixed_point);
		Fixed(float const fixed_point);
		Fixed &	operator=(Fixed const & rhs);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		
		int					_fixedPoint;
		static const int	_FRACT_BITS = FRACT_BITS;

};

std::ostream &	operator<<(std::ostream & out, Fixed const & fixed);

#endif
