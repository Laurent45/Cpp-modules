/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:52:54 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/31 17:02:18 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {

	Fixed a;
	Fixed const b( 5 );
	Fixed const c( 2 );
	Fixed const d( 7.5f);

	a = d / c;

	std::cout << a << std::endl;
	std::cout << (a < d) << std::endl;
	std::cout << (a > d) << std::endl;
	std::cout << (a == d) << std::endl;
	std::cout << (a != d) << std::endl;
	std::cout << (a <= d) << std::endl;
	std::cout << (a >= d) << std::endl;

	return 0;
}
