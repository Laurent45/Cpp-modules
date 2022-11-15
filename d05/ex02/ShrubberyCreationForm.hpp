/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:18:09 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/15 09:22:37 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

#define	SIGNED_GRADE	145
#define EXEC_GRADE		137

class ShrubberyCreationForm : public AForm
{
	public:
		// Cannonical Form
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const & copy);
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);		

		// Constructor
		ShrubberyCreationForm(std::string target);

		// Member functions
		virtual void	execute(Bureaucrat const & executor) const;
};

#endif
