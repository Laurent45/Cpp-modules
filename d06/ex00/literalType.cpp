/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   literalType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:04:02 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/18 11:39:05 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "literalType.hpp"

static bool	compare(char const * s1, char const * s2)
{
	int i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	if (s2[i] == '\0')
		return (true);
	return (false);
}


e_type	detectLiteralType(char const * literal)
{
	int	i;
	int		hasPoint = 0;
	char const * pseudosLit[8] = {"-inff", "+inff", "inff", "nanf"	
								, "-inf", "+inf", "inf", "nan"};

	if (literal[1] == '\0')
	{
		if (literal[0] >= '0' && literal[0] <= '9')
			return (INT);
		return (CHAR);
	}

	for (i = 0; i < 8; i++)
	{
		if (compare(literal, pseudosLit[i]))
		{
			if (i < 4)
				return (FLOAT);
			return (DOUBLE);
		}
	}

	i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while (literal[i + 1])
	{
		if ((!(literal[i] >= '0' && literal[i] <= '9') && literal[i] != '.') \
				|| (literal[i] == '.' && hasPoint))
			return (UNKNOWN);
		if (literal[i] == '.')
			hasPoint++;
		i++;
	}
	if (literal[i] == '.' \
			|| (literal[i - 1] == '.' && literal[i] == 'f')
			|| (!(literal[i] >= '0' && literal[i] <= '9') && literal[i] != 'f'))
		return (UNKNOWN);

	if (literal[i] == 'f')
		return (FLOAT);
	if (hasPoint)
		return (DOUBLE);
	return (INT);
}
