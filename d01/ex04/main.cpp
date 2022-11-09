/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:07:24 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/09 07:29:35 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	// Check if the user given a filename
	if (argc != 4)
	{
		std::cout << "Usage: ./a.out <filename> <s1> <s2>" << std::endl;
		return (0);
	}

	// Try to open the filename
	std::string filename = argv[1];
	std::ifstream ifs(filename.c_str());
	if (!ifs.good())
	{
		std::cout << "File unknown" << std::endl;
		return (1);
	}

	// Try to create and open the replace file
	filename += ".replace";
	std::ofstream ofs(filename.c_str());
	if (!ofs.good())
	{
		std::cout << "Open file failed" << std::endl;
		return (1);
	}
	
	
	ft_replace(ifs, ofs, argv[2], argv[3]);

	return (0);
}
