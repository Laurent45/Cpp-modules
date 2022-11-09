/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:37:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/09 07:28:06 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include <iostream>

void	ft_replace(std::ifstream &in, std::ofstream &out, char *arg1, char *arg2)
{
	std::string currentStr;
	std::string s1;
	std::string s2;
	size_t initPos;
	size_t findPos;

	s1 = arg1;
	s2 = arg2;
	while (getline(in, currentStr))
	{
		if (!s1.empty())
		{
			initPos = 0;
			findPos = 0;
			while ((findPos = currentStr.find(s1, initPos)) != std::string::npos)
			{
				currentStr.erase(findPos, s1.length());
				initPos = findPos + s2.length();
				currentStr.insert(findPos, s2);
			}
		}
		out << currentStr << std::endl;
	}
}
