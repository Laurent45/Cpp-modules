/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:16:25 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/05 08:41:09 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	AAnimal *pets[10];

	for (int i = 0; i < 5; i++)
		pets[i] = new Dog();

	std::cout << std::endl;

	for (int i = 5; i < 10; i++)
		pets[i] = new Cat();

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		pets[i]->makeSound();
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		delete pets[i];
		std::cout << std::endl;
	}

	std::cout << std::endl;

	Dog * dog1 = new Dog();
	Dog * dog2 = new Dog(*dog1);

	std::cout << std::endl;

	delete dog1;
	delete dog2;

	std::cout << std::endl;

	Cat * cat1 = new Cat();
	Cat * cat2 = new Cat(*cat1);

	std::cout << std::endl;

	delete cat1;
	delete cat2;

	/* AAnimal a = AAnimal(); */

	return 0;

}
