/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:22:46 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/03 08:48:24 by lfrederi         ###   ########.fr       */
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

		friend std::ostream & operator<<(std::ostream & out, ClapTrap const & clapTrap);

	protected:
		
		std::string		_name;
		unsigned int	_health;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

		bool	canAct(void) const;

};

#endif

