/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:16:25 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 15:57:46 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;

	std::cout << "animal type: " << animal->getType() << std::endl;
	std::cout << "dog type: " << dog->getType() << std::endl;
	std::cout << "cat type: " << cat->getType() << std::endl;
	std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
	std::cout << std::endl;

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	wrongCat->makeSound();
	std::cout << std::endl;


	delete animal;
	delete dog;
	delete cat;
	delete wrongCat;

	return 0;

}
