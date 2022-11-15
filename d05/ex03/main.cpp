/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:13:08 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/15 15:50:58 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

#define NB_BUREAUCRAT	10

int main(void)
{
	Intern intern;
	AForm * form = NULL;

	try
	{
		form = intern.makeForm("robotomy request", "Bender");
		if (form)
			std::cout << *form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	delete form;

	try
	{
		form = intern.makeForm("shrubbery creation", "Bender");
		if (form)
			std::cout << *form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	delete form;

	try
	{
		form = intern.makeForm("presidential pardon", "Bender");
		if (form)
			std::cout << *form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	delete form;

	try
	{
		form = intern.makeForm("robocdscsdcdscdequest", "Bender");
		if (form)
			std::cout << *form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	delete form;

	return (0);
}
