/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:15:59 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/08 10:53:44 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */
// Members methods
void	Harl::complainFilter(std::string level) const
{
	std::string alert[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int levelNumber = -1;

	for (int i = 0; i < 4; i++)
	{
		if (level == alert[i])
		{
			levelNumber = i;
			break ;
		}
	}

	switch (levelNumber)
	{
		case DEBUG:
			debug();
			info();
			warning();
			error();
			break ;
		case INFO:
			info();
			warning();
			error();
			break ;
		case WARNING:
			warning();
			error();
			break ;
		case ERROR:
			error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
					  << std::endl;
	}
}

/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

// methods
void	Harl::debug(void) const
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my " 
			  << "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
			  << "I really do !\n"
			  << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
			  << "You didn’t put enough bacon in my burger !\n"
			  << "If you did, I wouldn’t be asking for more !\n"
			  << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\n"
			  << "I’ve been coming for years whereas you started working "
			  << "here since last month.\n"
			  << std::endl;
}

void	Harl::error(void) const
{
	std::cout << "[ ERROR ] " << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now.\n"
			  << std::endl;
}

