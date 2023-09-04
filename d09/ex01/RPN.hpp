/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:42:46 by lfrederi          #+#    #+#             */
/*   Updated: 2023/07/08 17:22:53 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN
{
    private:
        bool    isOperator(char c) const;
        bool    doOperation(char c, std::stack<float> & stack) const;
        

    public:

        RPN(void);
        RPN(RPN const & copy);
        RPN & operator=(RPN const & rhs);
        ~RPN(void);

        void calculate(const char * str) const;

};

#endif
