/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:37:39 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 15:46:20 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		
		WrongCat(void);
		~WrongCat(void);
		WrongCat(WrongCat const & copy);
		WrongCat &	operator=(WrongCat const & rhs);
		
		void	makeSound(void) const;

};

#endif
