/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:59:37 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 19:53:15 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain * _brain;

	public:
		
		Cat(void);
		~Cat(void);
		Cat(Cat const & copy);
		Cat &	operator=(Cat const & rhs);
		
		virtual void	makeSound(void) const;
};

#endif
