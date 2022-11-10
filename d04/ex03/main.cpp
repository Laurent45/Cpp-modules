/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:53:56 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/09 14:20:36 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main(void)
{
	/*
	 * Tests about to MateriaSource
	 */	
	IMateriaSource * src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	
	std::cout << std::endl;
	
	AMateria * tmp = src->createMateria("ice");
	if (tmp)
		std::cout << "Materia created, type: " << tmp->getType() << std::endl;
	delete tmp;
	tmp = src->createMateria("cure");
	if (tmp)
		std::cout << "Materia created, type: " << tmp->getType() << std::endl;
	delete tmp;
	tmp = src->createMateria("Unknown");
	if (tmp)
		std::cout << "Materia created, type: " << tmp->getType() << std::endl;
	delete tmp;
	
	std::cout << std::endl;

	/*
	 * Tests about Character
	 */
	ICharacter * foo = new Character("Foo");
	foo->equip(src->createMateria("cure"));	
	foo->equip(src->createMateria("cure"));	
	foo->equip(src->createMateria("ice"));	
	foo->equip(src->createMateria("ice"));	

	std::cout << std::endl;

	ICharacter * bar = new Character(*dynamic_cast<Character *>(foo));

	std::cout << std::endl;

	bar->use(1, *foo);
	bar->use(3, *foo);

	std::cout << std::endl;
	
	ICharacter * toto = new Character("toto");
	toto->equip(src->createMateria("ice"));
	toto->equip(src->createMateria("ice"));
	toto->equip(src->createMateria("cure"));
	toto->equip(src->createMateria("cure"));

	std::cout << std::endl;

	toto->use(0, *bar);
	toto->use(2, *bar);

	std::cout << std::endl;

	*dynamic_cast<Character *>(toto) = *dynamic_cast<Character *>(bar); 

	std::cout << std::endl;

	toto->use(0, *bar);
	toto->use(2, *bar);

	std::cout << std::endl;

	delete foo;
	delete bar;
	delete toto;

	std::cout << std::endl;
	
	ICharacter * bob = new Character("Bob");
	ICharacter * jo = new Character("Jo");
	
	std::cout << std::endl;
	
	AMateria * cure = src->createMateria("cure");
	AMateria * ice1 = src->createMateria("ice");
	AMateria * ice2 = src->createMateria("ice");
	AMateria * ice3 = src->createMateria("ice");
	
	std::cout << std::endl;
	
	bob->equip(ice1);
	bob->equip(ice2);
	bob->equip(cure);
	bob->equip(ice3);
	
	std::cout << std::endl;
	
	bob->use(2, *jo);
	bob->unequip(2);
	
	bob->use(2, *jo);
	
	bob->unequip(0);
	bob->unequip(0);
	bob->unequip(0);
	bob->use(2, *jo);
	
	bob->equip(ice1);
	bob->equip(cure);
	bob->use(2, *jo);
	bob->use(1, *jo);
	bob->use(0, *jo);
	
	std::cout << std::endl;
	
	if (!ice1->isCollected())
		delete ice1;
	if (!ice2->isCollected())
		delete ice2;
	if (!ice3->isCollected())
		delete ice3;
	if (!cure->isCollected())
		delete cure;
	
	
	delete bob;
	delete jo;
	
	delete src;

	return 0;
}
