/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 06:44:38 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/19 06:50:47 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void	swap( T & a, T & b )
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const & min( T const & a, T const & b )
{
	return ( a < b ? a : b );
}

template<typename T>
T const & max( T const & a, T const & b )
{
	return ( a > b ? a : b );
}

#endif
