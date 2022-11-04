/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:51:31 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 15:43:37 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		
		Dog(void);
		~Dog(void);
		Dog(Dog const & copy);
		Dog &	operator=(Dog const & rhs);
		
		virtual void	makeSound(void) const;

};

#endif
