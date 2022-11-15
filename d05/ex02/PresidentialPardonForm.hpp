/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:37:47 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/15 14:13:04 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM
#define PRESIDENTIAL_PARDON_FORM

#include "AForm.hpp"

#define	PRES_SIGNED_GRADE	25
#define PRES_EXEC_GRADE		5

class PresidentialPardonForm : public AForm
{
	public:
		// Canonical form
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const & copy);
		PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);

		// Constructor
		PresidentialPardonForm(std::string target);

		// Member functions
		virtual void	execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & out, PresidentialPardonForm const & form);
#endif
