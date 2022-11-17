/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertFloat.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:10:01 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/17 18:48:49 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp" 
#include <climits>
#include <cmath>
#include <iostream>

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

void	convertFloat(char const * literal)
{
	float	f = static_cast<float>(strtod(literal, NULL));

	if (f == HUGE_VALF)
		return printOverflow(0);
	if (f == -HUGE_VALF)
		return printOverflow(1);
	if (f != f)
		return printOverflow(2);

	size_t len = 0;
	int point = 0;
	while (literal[len])
	{
		if (literal[len] == '.')
			point = len;
		len++;
	}

	int precision = 1;
	if (point)
		precision = len - point - 2;


	if (f >= 0.0f && f <= static_cast<float>(SCHAR_MAX))
	{
		char c = static_cast<char>(f);
		if (c >= 32 && c <= 127)
			std::cout << "char: \"" << c << "\"" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout.precision(precision);
	std::cout << std::fixed << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}
