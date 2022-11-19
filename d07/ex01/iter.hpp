/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 06:58:31 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/19 07:47:14 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void	iter( T * array, int length, void (*func)(T &) )
{
	if (!array || !func)
		return ;
	for (int i = 0; i < length; i++)
		func(array[i]);
}

template<typename T>
void	print( T & e )
{
	std::cout << "Element: " << e << std::endl;
}

template<typename T>
void	increment( T & e )
{
	e++;
}

#endif
