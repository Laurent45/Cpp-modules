/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:59:04 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/14 13:24:52 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:

		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const & copy);
		Bureaucrat &	operator=(Bureaucrat const & rhs);

		Bureaucrat(std::string name, int grade);
		
		std::string const &	getName(void) const;
		int		getGrade(void) const;
		Bureaucrat & operator++(void);
		Bureaucrat & operator--(void);

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

std::ostream &	operator<<(std::ostream & out, Bureaucrat & bureaucrat);

#endif
