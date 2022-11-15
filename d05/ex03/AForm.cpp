/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:46:06 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/15 13:23:59 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
AForm::AForm(void)
	: _name(""), _signed(false), _gradeToSigned(1), _gradeToExec(1)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(AForm const & copy)
	: _name(copy._name), _signed(copy._signed), _gradeToSigned(copy._gradeToSigned)
	  , _gradeToExec(copy._gradeToExec)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm & AForm::operator=(AForm const & rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;

	std::cout << "AForm copy assignment called" << std::endl;
	return (*this);
}

// Constructors
AForm::AForm(std::string name, std::string target, int gradeToSigned, int gradeToExec)
	: _name(name), _target(target), _signed(false), _gradeToSigned(gradeToSigned)
	  , _gradeToExec(gradeToExec)
{
	if (gradeToSigned < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSigned > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();

	std::cout << "AForm constructor called (name: " << name
			  << ", target: " << target
			  << ", gradeToSigned: " << gradeToSigned
			  << ", gradeToExec: " << gradeToExec << ")" << std::endl;
}

// Accesseurs
std::string const &	AForm::getName(void) const
{
	return (this->_name);
}

std::string const &	AForm::getTarget(void) const
{
	return (this->_target);
}

bool	AForm::isSigned(void) const
{
	return (this->_signed);
}

int		AForm::getGradeToSigned(void) const
{
	return (this->_gradeToSigned);
}

int		AForm::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

void	AForm::setSigned(bool newStatus)
{
	this->_signed = newStatus;
}

// Members methods
void	AForm::beSigned(Bureaucrat & bureaucrat)
{
	if (this->_signed)
	{
		std::cout << "Form already sign" << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() > this->_gradeToSigned)
		throw AForm::GradeTooLowException();
	this->_signed = true;
	std::cout << GRN "Form signed !" NC << std::endl;
}

void	AForm::checkRequirements(Bureaucrat const & bureaucrat) const
{
	if (!this->_signed || bureaucrat.getGrade() > this->_gradeToExec)
		throw AForm::ExecNotAllowedException();
}

// Exception classes
const char *	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Exception: AForm's grade is too high");
}

const char *	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Exception: AForm's grade is too low");
}

const char * AForm::ExecNotAllowedException::what(void) const throw()
{
	return 
		("Exception: Execution not allowed, form's grade to exec is too high or form isn't signed");
}
/* ************************************************************************** */
//						           FUNCTION								  //
/* ************************************************************************** */
std::ostream & operator<<(std::ostream & out, AForm const & form)
{
	out << "AForm -> ("
		<< "name: " << form.getName()
		<< ", signed: " << (form.isSigned() ? "true": "false")
		<< ", grade to signed: " << form.getGradeToSigned()
		<< ", grade to exec: " << form.getGradeToExec() << ")";

	return (out);
}
