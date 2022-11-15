/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:13:23 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/15 08:53:50 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
#define A_FORM_HPP

#include <exception>
#include <string>

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define NC	"\e[0m"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		std::string const	_target;
		bool				_signed;
		int const			_gradeToSigned;
		int	const			_gradeToExec;

	public:
		// Canonical form
		AForm(void);
		virtual ~AForm(void);
		AForm(AForm const & copy);
		AForm &	operator=(AForm const & rhs);	

		// Constructor	
		AForm(std::string name, std::string target, int gradeToSigned, int gradeToExec);

		// Accesseurs
		std::string const &	getName(void) const;
		std::string const &	getTarget(void) const;
		bool				isSigned(void) const;
		int					getGradeToSigned(void) const;
		int					getGradeToExec(void) const;
		void				setSigned(bool newStatus);

		// Members function
		void	beSigned(Bureaucrat & bureaucrat);

		// Function virtual pure
		virtual void	execute(Bureaucrat const & executor) const = 0;

		// Exception
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what(void) const throw(); 
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what(void) const throw(); 
		};

		class ExecNotAllowedException : public std::exception
		{
			public:
				virtual const char * what(void) const throw(); 
		};

	protected:
		void	checkRequirements(Bureaucrat const & bureaucrat) const;	

};

std::ostream & operator<<(std::ostream & out, AForm const & form);

#endif
