/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:08:26 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/31 08:30:51 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);


	private:
		
		int					_fixed_point;
		static const int	_FRACT_BITS = FRACT_BITS;
		

};


#endif
