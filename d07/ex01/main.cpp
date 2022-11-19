/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 07:07:49 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/19 07:47:51 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	printInt( int & e )
{
	std::cout << "Element: " << e << std::endl;
}

void	printFloat( float & e )
{
	std::cout << "Element: " << e << std::endl;
}

int main( void )
{
	int arrayInt[5] = {1, 2, 3, 4, 5};
	iter<int>(arrayInt, 5, &printInt);

	std::cout << std::endl;

	float arrayFloat[5] = {1.42f, 2.42f, 3.42f, 4.42f, 5.42f};
	iter<float>(arrayFloat, 5, &printFloat);

	std::cout << std::endl;

	iter<int>(arrayInt, 5, &increment);
	iter<float>(arrayFloat, 5, &increment);

	iter<int>(arrayInt, 5, &print);
	std::cout << std::endl;
	iter<float>(arrayFloat, 5, &print);

	return (0);
}
