/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 07:11:12 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/15 13:22:26 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", "", SIGNED_GRADE, EXEC_GRADE)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy)
	: AForm(copy)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
		this->setSigned(rhs.isSigned());

	std::cout << "ShrubberyCreationForm copy assignment called" << std::endl;
	return (*this);
}

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", target, SIGNED_GRADE, EXEC_GRADE)
{
	std::cout << "ShrubberyCreationForm constructor called with parameters" << std::endl;
}

// Member Function
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		checkRequirements(executor);
	}
	catch (std::exception & e)
	{
		throw ;
	}

	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream out(filename.c_str());
	if (!out.good())
	{
		std::cerr << "Open file (" << filename << ") failed" << std::endl;
		return ;
	}
	std::string tree = 
"	  &&& &&  & &&\n\
      && &\\/&\\|& ()|/ @, &&\n\
      &\\/(/&/&||/& /_/)_&/_&\n\
   &() &\\/&|()|/&\\/ '% & ()\n\
  &_\\_&&_\\ |& |&&/&__%_/_& &&\n\
&&   && & &| &| /& & % ()& /&&\n\
 ()&_---()&\\&\\|&&-&&--%---()~\n\
     &&     \\|||\n\
             |||\n\
             |||\n\
             |||\n\
       , -=-~  .-^- _\n";
	
	for (int i = 0; i < 5; i++)
		out << tree << std::endl;
	std::cout << GRN "Form executed !" NC << std::endl;
}
