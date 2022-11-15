/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:13:08 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/15 14:22:07 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define NB_BUREAUCRAT	10

int main(void)
{
	Bureaucrat * bureaucrats[NB_BUREAUCRAT] = {NULL};
	for (int i = 0; i < NB_BUREAUCRAT; i++)
	{
		try
		{
			bureaucrats[i] = new Bureaucrat("bureaucrat_", (i * 24) + 5);
		}
		catch (std::exception & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < NB_BUREAUCRAT; i++)
	{
		if (bureaucrats[i])
			std::cout << *bureaucrats[i] << std::endl;
		else
			std::cout << "null" << std::endl;
	}

	std::cout << std::endl;

	AForm * form = new ShrubberyCreationForm("garden");
	std::cout << std::endl;
	std::cout << *dynamic_cast<ShrubberyCreationForm*>(form) << std::endl;
	for (int i = 0; i < NB_BUREAUCRAT; i++)
	{
		try
		{
			if (bureaucrats[i])
			{
				std::cout << *bureaucrats[i] << std::endl;
				form->beSigned(*bureaucrats[i]);
			}
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << NC << std::endl;
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < NB_BUREAUCRAT; i++)
	{
		try
		{
			if (bureaucrats[i])
			{
				std::cout << *bureaucrats[i] << std::endl;
				form->execute(*bureaucrats[i]);
			}
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << NC << std::endl;
		}
	}

	std::cout << std::endl;
	
	delete form;

	std::cout << std::endl;

	form = new RobotomyRequestForm("tesla");
	std::cout << std::endl;
	std::cout << *dynamic_cast<RobotomyRequestForm*>(form) << std::endl;
	for (int i = NB_BUREAUCRAT - 1; i >= 0; i--)
	{
		try
		{
			if (bureaucrats[i])
			{
				std::cout << *bureaucrats[i] << std::endl;
				form->beSigned(*bureaucrats[i]);
			}
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << NC << std::endl;
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < NB_BUREAUCRAT; i++)
	{
		try
		{
			if (bureaucrats[i])
			{
				std::cout << *bureaucrats[i] << std::endl;
				form->execute(*bureaucrats[i]);
			}
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << NC << std::endl;
		}
	}

	std::cout << std::endl;
	
	delete form;

	std::cout << std::endl;

	form = new PresidentialPardonForm("pepe");
	std::cout << std::endl;
	std::cout << *dynamic_cast<PresidentialPardonForm*>(form) << std::endl;
	for (int i = NB_BUREAUCRAT - 1; i >= 0; i--)
	{
		try
		{
			if (bureaucrats[i])
				bureaucrats[i]->signForm(*form);
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << NC << std::endl;
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < NB_BUREAUCRAT; i++)
	{
		try
		{
			if (bureaucrats[i])
				bureaucrats[i]->executeForm(*form);
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << NC << std::endl;
		}
	}

	std::cout << std::endl;
	
	delete form;

	std::cout << std::endl;

	for (int i = 0; i < NB_BUREAUCRAT; i++)
	{
		if (bureaucrats[i])
			delete bureaucrats[i];
	}

	return (0);
}
