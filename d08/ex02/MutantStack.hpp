/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:10:54 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/28 12:27:20 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <deque>
#include <stack>
#include <cstddef>

template< typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> 
{
	public:
		typedef		typename Container::iterator		iterator;
		typedef		typename Container::const_iterator	const_iterator;

		MutantStack()
			: std::stack<T, Container>() {}

		~MutantStack() {}

		MutantStack(const MutantStack<T, Container> & copy)
			: std::stack<T, Container>(copy.c) {}

		MutantStack<T, Container> & operator=(const MutantStack<T, Container> & rhs)
		{
			if (this != &rhs)
			{
				this->c = rhs.c;
			}
		}

		iterator			begin() { return this->c.begin(); }
		const_iterator		begin() const { return this->c.begin(); }
		iterator			end() { return this->c.end(); }
		const_iterator		end() const { return this->c.end(); }
};

#endif
