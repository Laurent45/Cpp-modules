/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:08:26 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/31 16:45:15 by lfrederi         ###   ########.fr       */
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
		Fixed	&operator=(Fixed const & rhs);
		~Fixed(void);
		Fixed(const int fixed_point);
		Fixed(const float fixed_point);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;

		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;
		

	private:
		
		int					_fixed_point;
		static const int	_FRACT_BITS = FRACT_BITS;

};

std::ostream	&operator<<(std::ostream &out, const Fixed &rhs);

#endif
