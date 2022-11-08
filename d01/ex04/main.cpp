/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:07:24 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/08 16:41:08 by lfrederi         ###   ########.fr       */
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
	if (ifs.is_open() == false)
	{
		std::cout << "File unknown" << std::endl;
		return (1);
	}

	// Check if filename is a file or a directory
	ifs.seekg(0, ifs.end);
	if (!ifs.good())
	{
		std::cout << "This filename is a directory" << std::endl;
		return (1);
	}
	ifs.seekg(0, ifs.beg);

	// Try to create and open the replace file
	filename += ".replace";
	std::ofstream ofs(filename.c_str());
	if (ofs.is_open() == false)
	{
		std::cout << "Open file failed" << std::endl;
		return (1);
	}

	
	ft_replace(ifs, ofs, argv[2], argv[3]);

	return (0);
}
