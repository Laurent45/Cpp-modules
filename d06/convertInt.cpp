/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertInt.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:32:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/17 16:42:11 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <cmath>
#include <climits>
#include <iostream>

static void	printOverflow(void)
{
	std::cout << "char: impossible\n"
			  << "int: overflow/underflow\n"
			  << "float: impossible\n"
			  << "double: impossible" << std::endl;
}

void	convertInt(char const * literal)
{
	double	convert = strtod(literal, NULL);

	if (convert == HUGE_VAL || convert == -HUGE_VAL\
		|| (convert < static_cast<double>(INT_MIN))\
		|| (convert > static_cast<double>(INT_MAX)))
		return printOverflow();

	int		n = static_cast<int>(convert);

	if (n >= 0 && n <= SCHAR_MAX)
	{
		char c = static_cast<char>(n);
		if (c >= 32 && c <= 127)
			std::cout << "char: \"" << c << "\"" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout.precision(1);
	std::cout << std::fixed << "float: " << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << std::endl;
}

