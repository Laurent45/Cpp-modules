/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:42:40 by lfrederi          #+#    #+#             */
/*   Updated: 2023/07/08 17:33:31 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <cmath>
#include <iostream>
#include <stack>
#include <cctype>
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

void    RPN::calculate(const char * str) const
{
    std::stack<float>   stack;
    bool                error = false;
    size_t              i = 0;

    while (str[i])
    {
        if (std::isdigit(str[i]))
            stack.push(str[i] - '0');
        else if (isOperator(str[i]))
        {
            if (!doOperation(str[i], stack))
            {
                error = true;
                break ;
            }
        }
        else if (!std::isspace(str[i]))
        {
            std::cout << "Error: Invalid character: " << str[i] << std::endl;
            error = true;
            break;
        }
        i++;
    }

    if (!error)
    {
        if (stack.size() == 1)
            std::cout << stack.top() << std::endl;
        else
            std::cout << "Error: RPN expression is not valid" << std::endl;
    }
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

bool    RPN::doOperation(char c, std::stack<float> & stack) const
{
    float   tmp;

    if (stack.size() < 2)
    {
        std::cout << "Error: RPN expression is invaild" << std::endl;
        return false;
    }

    tmp = stack.top();
    stack.pop();

    if (c == '+')
        tmp = stack.top() + tmp;
    else if (c == '-')
        tmp = stack.top() - tmp;
    else if (c == '*')
        tmp = stack.top() * tmp;
    else if (c == '/')
        tmp = stack.top() / tmp;
    else
        throw std::exception();

    stack.pop();

    if (tmp == -HUGE_VAL || tmp == +HUGE_VAL)
    {
        std::cout << "Error: Out of range reached" << std::endl;
        return false;
    }
    stack.push(tmp);
    return true;
}
