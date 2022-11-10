/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:22:46 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/10 14:07:40 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>
#include <iostream>
#include <climits>

#define CLAP_HEALTH	10
#define CLAP_ENERGY	10
#define	CLAP_ATTACK	0

class ClapTrap
{
	public:
		
		ClapTrap(void);
		ClapTrap(ClapTrap const & copy);
		~ClapTrap(void);
		ClapTrap &	operator=(ClapTrap const & rhs);

		ClapTrap(std::string const & name);

		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getName(void) const;
		unsigned int	getHealth(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;


	private:
		
		std::string		_name;
		unsigned int	_health;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

		bool	canAct(void) const;

};

std::ostream & operator<<(std::ostream & out, ClapTrap const & clapTrap);

#endif

