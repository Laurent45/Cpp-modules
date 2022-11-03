/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:38:52 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/03 13:09:11 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

#define FRAG_HEALTH	100
#define FRAG_ENERGY	100
#define FRAG_ATTACK	30

class FragTrap : virtual public ClapTrap
{
	public:
		
		FragTrap(void);
		~FragTrap(void);
		FragTrap(FragTrap const & copy);
		FragTrap &	operator=(FragTrap const & rhs);

		FragTrap(std::string const & name);

		void	highFivesGuys(void) const;

		friend std::ostream & operator<<(std::ostream & out, FragTrap const & fragTrap);

};

#endif
