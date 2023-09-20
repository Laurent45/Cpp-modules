/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:42:46 by lfrederi          #+#    #+#             */
/*   Updated: 2023/09/20 11:37:19 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <list>

class RPN
{
  private:
    bool    isOperator(char c) const;
    void    doOperation(char c, std::stack<int, std::list<int> > & stack) const;


  public:

    RPN(void);
    RPN(RPN const & copy);
    RPN & operator=(RPN const & rhs);
    ~RPN(void);

    int calculate(const char * str) const;

};

#endif
