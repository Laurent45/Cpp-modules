/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:59:37 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 15:43:45 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		
		Cat(void);
		~Cat(void);
		Cat(Cat const & copy);
		Cat &	operator=(Cat const & rhs);
		
		virtual void	makeSound(void) const;
};

#endif
