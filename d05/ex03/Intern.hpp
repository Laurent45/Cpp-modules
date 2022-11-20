/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:28:16 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/20 16:52:38 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <string>

#define NB_FORM	3
class AForm;

class Intern
{
	public:
		// Canonical form
		Intern(void);
		~Intern(void);
		Intern(Intern const & copy);
		Intern &	operator=(Intern const & rhs);	
		
		// Member function
		AForm * makeForm(std::string const & nameForm, std::string const & target) const;

	private:
		AForm *	createShrubberyCreationForm(std::string const & target) const;
		AForm *	createRobotomyRequestForm(std::string const & target) const;
		AForm * createPresidentialPardonForm(std::string const & target) const;

};

#endif
