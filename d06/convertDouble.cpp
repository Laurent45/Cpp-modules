/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertDouble.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:16:08 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/17 18:49:06 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <iostream>
#include <climits>
#include <cmath>
#include <cfloat>

static void	printOverflow(int type)
{
	std::cout << "char: impossible\n"
			  << "int: impossible\n";

	switch (type)
	{
		case (0):
			std::cout << "float: +inff\ndouble: +inf";
			break;
		case (1):
			std::cout << "float: -inff\ndouble: -inf";
			break;
		default:
			std::cout << "float: nanf\ndouble: nan";
	}
	std::cout << std::endl;
}

void	convertDouble(char const * literal)
{
	double	d = strtod(literal, NULL);

	if (d == HUGE_VAL)
		return printOverflow(0);
	if (d == -HUGE_VAL)
		return printOverflow(1);
	if (d != d)
		return printOverflow(2);

	size_t len = 0;
	int point = 0;
	while (literal[len])
	{
		if (literal[len] == '.')
			point = len;
		len++;
	}

	int precision = len - point - 1;

	if (d >= 0.0f && d <= static_cast<float>(SCHAR_MAX))
	{
		char c = static_cast<char>(d);
		if (c >= 32 && c <= 127)
			std::cout << "char: \"" << c << "\"" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "int: overflow/underflow\n";
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout.precision(precision);
	if (d < static_cast<double>(FLT_MIN) || d > static_cast<double>(FLT_MAX))
		std::cout << "float: overflow/underflow\n";
	else
		std::cout << std::fixed << "float: " << static_cast<float>(d) << "f\n";
	std::cout << std::fixed << "double: " << d << std::endl;
}
