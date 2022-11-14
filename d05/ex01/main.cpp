/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:13:08 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/14 16:59:10 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main(void)
{
	{
		try
		{
			Form form("form", 23, 323);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Form form("form", 0, 12);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		Form form("contract", 12, 23);
		Bureaucrat bureaucrat("Foo", 45);
		try
		{
			bureaucrat.signForm(form);
			form.beSigned(bureaucrat);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		Form form("contract", 12, 23);
		Bureaucrat bureaucrat("Foo", 1);
		try
		{
			form.beSigned(bureaucrat);
			bureaucrat.signForm(form);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}
