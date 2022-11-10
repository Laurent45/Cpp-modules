/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:57:16 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/09 10:37:25 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
		this->_materias[i] = NULL;

	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (!this->_materias[i])
			break ;
		delete this->_materias[i];
	}

	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & copy)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (!copy._materias[i])
			break ;
		this->_materias[i] = copy._materias[i]->clone();
	}

	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < MAX_MATERIAS; i++)
		{
			if (!this->_materias[i])
				break ;
			delete this->_materias[i];
		}
		
		for (int i = 0; i < MAX_MATERIAS; i++)
		{
			if (!rhs._materias[i])
				break ;
			this->_materias[i] = rhs._materias[i]->clone();
		}
	}

	std::cout << "MateriaSource copy assignment called" << std::endl;
	return (*this);
}

// Members methods
void	MateriaSource::learnMateria(AMateria * materia)
{
	if (!materia)
		return ;

	int i = 0;
	while (i < MAX_MATERIAS && this->_materias[i])
		i++;
	if (i == MAX_MATERIAS)
	{
		delete materia;
		std::cout << "Materias are full!" << std::endl;
	}
	else
		this->_materias[i] = materia;
}

AMateria *	MateriaSource::createMateria(const std::string & type)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (this->_materias[i] == NULL)
			break ;
		if (this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}

	std::cout << "None Materia with type -> " << type << std::endl;
	return (NULL);
}

/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

//	Static attributes


// Static methods


// Constructor
