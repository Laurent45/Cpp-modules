/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:13:08 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/15 13:57:03 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	{
		try 
		{
			Bureaucrat bureaucrat("FooBureaucrat", 0);
		} 
		catch (std::exception & e) 
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try 
		{
			Bureaucrat bureaucrat("FooBureaucrat", 151);
		} 
		catch (std::exception & e) 
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{

		Bureaucrat bureaucrat("FooBureaucrat", 3);
		try 
		{
			std::cout << bureaucrat << std::endl;
			++bureaucrat;
			std::cout << bureaucrat << std::endl;
			++bureaucrat;
			std::cout << bureaucrat << std::endl;
			++bureaucrat;
			std::cout << bureaucrat << std::endl;
			++bureaucrat;
		} 
		catch (std::exception & e) 
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
		std::cout << std::endl;

	{

		Bureaucrat bureaucrat("FooBureaucrat", 149);
		try 
		{
			std::cout << bureaucrat << std::endl;
			--bureaucrat;
			std::cout << bureaucrat << std::endl;
			--bureaucrat;
			std::cout << bureaucrat << std::endl;
			--bureaucrat;
			std::cout << bureaucrat << std::endl;
			--bureaucrat;
		} 
		catch (std::exception & e) 
		{
			std::cerr << e.what() << std::endl;
		}
	}


	return (0);
}
