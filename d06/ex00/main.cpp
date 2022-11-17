/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:30:58 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/17 16:47:15 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include "literalType.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return (0);
	}

	e_type types[4] = {CHAR, INT, FLOAT, DOUBLE};
	void (*converts[])(char const *) = {
		&convertChar
		, &convertInt
		, &convertFloat
		, &convertDouble};

	e_type type = detectLiteralType(argv[1]);
	for (int i = 0; i < 4; i++)
	{
		if (type == types[i])
		{
			converts[i](argv[1]);
			return (0);
		}
	}

	std::cout << "char: impossible\n"
			  << "int: impossible\n"
			  << "float: nanf\n"
			  << "double: nan" << std::endl;

	return (0);
}
