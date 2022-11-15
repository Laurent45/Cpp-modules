/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:02:06 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/15 14:16:07 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

#define	ROBO_SIGNED_GRADE	72
#define ROBO_EXEC_GRADE		45

class RobotomyRequestForm : public AForm
{
	public:
		// Canonical Form`
		RobotomyRequestForm(void);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const & copy);
		RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);
		
		// Constructor
		RobotomyRequestForm(std::string target);

		// Member functions
		virtual void	execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & out, RobotomyRequestForm const & form);

#endif
