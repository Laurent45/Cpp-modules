/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:15:59 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/08 10:30:54 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */
// Members methods
void	Harl::complain(std::string level) const
{
	void (Harl::*f[4])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string alert[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == alert[i])
		{
			(this->*f[i])();
			return ;
		}
	}

	std::cout << "level -> " << level << ", doesn't exist !" << std::endl;
}

/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

// methods
void	Harl::debug(void) const
{
	std::cout << "I love having extra bacon for my " 
			  << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
			  << "I really do !"
			  << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn’t put enough bacon in my burger ! "
			  << "If you did, I wouldn’t be asking for more !"
			  << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I’ve been coming for years whereas you started working "
			  << "here since last month."
			  << std::endl;
}

void	Harl::error(void) const
{
	std::cout << "This is unacceptable ! I want to speak to the manager now."
			  << std::endl;
}

