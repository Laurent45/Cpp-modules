/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:27:51 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/27 11:15:07 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <deque>
#include <cstddef>

template< typename T, typename Container = std::deque<T> >
class MutantStack 
{
	public:
		typedef		T									value_type;
		typedef		Container							container_type;	
		typedef		size_t								size_type;
		typedef		typename Container::iterator		iterator;
		typedef		typename Container::const_iterator	const_iterator;

		explicit MutantStack(container_type const & container = container_type());

		bool				empty() const;
		size_type			size() const;
		value_type &		top();
		const value_type &	top() const;
		void				push(const value_type& val);
		void				pop();


		iterator			begin() { return _stack.begin(); }
		const_iterator		begin() const { return _stack.begin(); }
		iterator			end() { return _stack.end(); }
		const_iterator		end() const { return _stack.end(); }


	private:
		container_type	_stack;
};

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(container_type const & container)
	: _stack(container) {}

template<typename T, typename Container>
bool	MutantStack<T, Container>::empty() const
{
	return (this->_stack.empty());
}

template<typename T, typename Container>
size_t	MutantStack<T, Container>::size() const
{
	return (this->_stack.size());
}
template<typename T, typename Container>
T &	MutantStack<T, Container>::top()
{
	return (this->_stack.back());
}

template<typename T, typename Container>
const T &	MutantStack<T, Container>::top() const
{
	return (this->_stack.back());
}

template<typename T, typename Container>
void	MutantStack<T, Container>::push(const value_type& val)
{
	return (this->_stack.push_back(val));
}

template<typename T, typename Container>
void	MutantStack<T, Container>::pop()
{
	return (this->_stack.pop_back());
}

#endif
