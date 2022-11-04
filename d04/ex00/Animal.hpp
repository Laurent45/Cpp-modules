/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:39:29 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 15:43:52 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string _type;
		
		Animal(std::string const & type);

	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(Animal const & copy);
		Animal &	operator=(Animal const & rhs);
		
		std::string const &	getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
