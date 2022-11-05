/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:39:29 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 19:51:47 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
	protected:
		std::string _type;
		
		AAnimal(std::string const & type);

	public:
		AAnimal(void);
		virtual ~AAnimal(void);
		AAnimal(AAnimal const & copy);
		AAnimal &	operator=(AAnimal const & rhs);
		
		std::string const &	getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
