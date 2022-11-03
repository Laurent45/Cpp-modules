/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:41:14 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/03 08:51:42 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

#define SCAV_HEALTH 100
#define SCAV_ENERGY	50
#define SCAV_ATTACK	20

class ScavTrap : public ClapTrap 
{
	public:

		ScavTrap(void);
		ScavTrap(ScavTrap const & copy);
		~ScavTrap(void);
		ScavTrap & operator=(ScavTrap const & rhs);

		ScavTrap(std::string const & name);

		void	attack(std::string const & target);
		void	guardGate(void) const;

		friend std::ostream & operator<<(std::ostream & out, ScavTrap const & ScavTrap);

};

#endif
