/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:42:40 by lfrederi          #+#    #+#             */
/*   Updated: 2023/09/20 11:38:55 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <cmath>
#include <iostream>
#include <stack>
#include <cctype>
#include <stdexcept>
#include <string>

/****************
 * CANONICAL FORM
 ****************/

RPN::RPN(void)
{}

RPN::RPN(RPN const & copy)
{
  (void) copy;
}

RPN &RPN::operator=(RPN const &rhs)
{
  (void) rhs;
  return (*this);
}

RPN::~RPN(void)
{}

/******************************************************************************/

/****************
 * PUBLIC METHODS
 ****************/

int RPN::calculate(const char * str) const
{
  std::stack<int, std::list<int> >  stack;
  size_t                            i = 0;

  while (str[i])
  {
    if (std::isdigit(str[i]))
      stack.push(str[i] - '0');
    else if (isOperator(str[i]))
      doOperation(str[i], stack);
    else if (!std::isspace(str[i]))
      throw std::runtime_error("Error: Invalid character: ");
    i++;
  }

  if (stack.size() == 1)
    return stack.top();
  throw std::runtime_error("Error: RPN expression is not valid");
}

/******************************************************************************/

/*****************
 * PRIVATE METHODS
 *****************/

bool    RPN::isOperator(char c) const
{
  const std::string operators("+-*/");
  std::string::const_iterator it = operators.begin();

  for (; it != operators.end(); it++)
  {
    if (c == *it)
      return true;
  }
  return false;
}

void  RPN::doOperation(char c, std::stack<int, std::list<int> > & stack) const
{
  int   tmp;

  if (stack.size() < 2)
    throw std::runtime_error("Error: RPN expression is invaild");

  tmp = stack.top();
  stack.pop();

  if (c == '+')
    tmp = stack.top() + tmp;
  else if (c == '-')
    tmp = stack.top() - tmp;
  else if (c == '*')
    tmp = stack.top() * tmp;
  else if (c == '/')
  {
    if (tmp == 0)
      throw std::runtime_error("Error: Impossible to divided by 0");
    tmp = stack.top() / tmp;
  }
  else
    throw std::runtime_error("Error: Operator invalid");

  stack.pop();

  if (tmp == -HUGE_VAL || tmp == +HUGE_VAL)
    throw std::runtime_error("Error: Out of range reached");

  stack.push(tmp);
}
