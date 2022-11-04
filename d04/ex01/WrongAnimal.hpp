/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:31:35 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 15:43:18 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
		
		WrongAnimal(std::string const & type);

	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal(WrongAnimal const & copy);
		WrongAnimal &	operator=(WrongAnimal const & rhs);
		
		std::string const &	getType(void) const;
		void	makeSound(void) const;

};

#endif
