/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:13:28 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/10 14:42:03 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		
		DiamondTrap(void);
		~DiamondTrap(void);
		DiamondTrap(DiamondTrap const & copy);
		DiamondTrap &	operator=(DiamondTrap const & rhs);
		
		DiamondTrap(std::string const & name);

		void	attack(const std::string & target);
		void	whoAmI(void) const;	

		virtual std::string		getName(void) const;

	private:
		std::string	_name;


};

std::ostream & operator<<(std::ostream & out, DiamondTrap const & diamondTrap);

#endif
