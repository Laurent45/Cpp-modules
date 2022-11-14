/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:46:06 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/14 17:05:45 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
Form::Form(void)
	: _name(""), _signed(false), _gradeToSigned(1), _gradeToExec(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(Form const & copy)
	: _name(copy._name), _signed(copy._signed), _gradeToSigned(copy._gradeToSigned)
	  , _gradeToExec(copy._gradeToExec)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form & Form::operator=(Form const & rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;

	std::cout << "Form copy assignment called" << std::endl;
	return (*this);
}

// Constructors
Form::Form(std::string name, int gradeToSigned, int gradeToExec)
	: _name(name), _signed(false), _gradeToSigned(gradeToExec), _gradeToExec(gradeToExec)
{
	if (gradeToSigned < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (gradeToSigned > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();

	std::cout << "Form constructor called (name: " << name
			  << ", gradeToSigned: " << gradeToSigned
			  << ", gradeToExec: " << gradeToExec << ")" << std::endl;
}

// Getteurs
std::string const &	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::isSigned(void) const
{
	return (this->_signed);
}

int		Form::getGradeToSigned(void) const
{
	return (this->_gradeToSigned);
}

int		Form::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

// Members methods
void	Form::beSigned(Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSigned)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

// Exception classes
const char *	Form::GradeTooHighException::what(void) const throw()
{
	return "Exception: Form's grade is too high";
}

const char *	Form::GradeTooLowException::what(void) const throw()
{
	return "Exception: Form's grade is too low";
}
/* ************************************************************************** */
//						           FUNCTION								  //
/* ************************************************************************** */
std::ostream & operator<<(std::ostream & out, Form const & form)
{
	out << "Form -> ("
		<< "name: " << form.getName()
		<< ", signed: " << (form.isSigned() ? "true": "false")
		<< ", grade to signed: " << form.getGradeToSigned()
		<< ", grade to exec: " << form.getGradeToExec() << ")";

	return (out);
}
