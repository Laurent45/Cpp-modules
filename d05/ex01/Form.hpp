/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:13:23 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/20 16:40:12 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSigned;
		int	const			_gradeToExec;

	public:
		// Canonical form
		Form(void);
		~Form(void);
		Form(Form const & copy);
		Form &	operator=(Form const & rhs);	

		// Constructor	
		Form(std::string name, int gradeToSigned, int gradeToExec);

		// Getteurs
		std::string const &	getName(void) const;
		bool				isSigned(void) const;
		int					getGradeToSigned(void) const;
		int					getGradeToExec(void) const;
		void				setSigned(bool newStatus);

		// Members function
		void	beSigned(Bureaucrat const & bureaucrat);

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

};

std::ostream & operator<<(std::ostream & out, Form const & form);

#endif
