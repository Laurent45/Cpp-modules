/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:45:38 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/18 12:23:40 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>
#include <iostream>
#include <ctime>
#include <cstdlib>

/* ************************************************************************** */
//						           MEMBER									  //
/* ************************************************************************** */
Base::~Base(void)
{
	std::cout << "Base destructor called" << std::endl;
}


/* ************************************************************************** */
//						           NO-MEMBER								  //
/* ************************************************************************** */
Base *	generate(void)
{
	std::srand(std::time(NULL));
	int random = rand() % 3;

	std::cout << "Random number generated is " << random << std::endl;
	
	switch (random)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
	}
	return (new C());
}

void	identify(Base * p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Object type is A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "Object type is B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "Object type is C" << std::endl;
}

void	identify(Base & p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "Object type is A" << std::endl;
	}
	catch (std::exception & e)
	{
		try
		{
			dynamic_cast<B &>(p);
			std::cout << "Object type is B" << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << "Object type is C" << std::endl;
		}
	}
}
