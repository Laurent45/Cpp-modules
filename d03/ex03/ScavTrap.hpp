/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:41:14 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/11 09:15:42 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

#define SCAV_HEALTH 100
#define SCAV_ENERGY	50
#define SCAV_ATTACK	20

class ScavTrap : virtual public ClapTrap 
{
	public:

		ScavTrap(void);
		ScavTrap(ScavTrap const & copy);
		~ScavTrap(void);
		ScavTrap & operator=(ScavTrap const & rhs);

		ScavTrap(std::string const & name);

		virtual void	attack(std::string const & target);
		void	guardGate(void) const;

};

std::ostream & operator<<(std::ostream & out, ScavTrap const & scavTrap);

#endif
