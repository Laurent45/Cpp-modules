/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:08:10 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 16:35:48 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

#define	NB_IDEAS	100

class Brain
{
	private:
		std::string	_ideas[NB_IDEAS];

	public:
		
		Brain(void);
		~Brain(void);
		Brain(Brain const & copy);
		Brain &	operator=(Brain const & rhs);

};

#endif
