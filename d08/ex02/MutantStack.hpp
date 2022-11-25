/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:27:51 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/24 18:07:24 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <deque>

template< typename T, typename Container = std::deque<T> >
class MutantStack 
{
	public:
		typedef		T				value_type;
		typedef		Container		container_type;	
		typedef		unsigned int	size_type;

		explicit MutantStack(container_type const & container = container_type());

		bool				empty() const;
		size_type			size() const;
		value_type &		top();
		const value_type &	top() const;
		void				push(const value_type& val);
		void				pop();


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
typename MutantStack<T, Container>::size_type	MutantStack<T, Container>::size() const
{
	return (this->_stack.size());
}
template<typename T, typename Container>
typename MutantStack<T, Container>::value_type &	MutantStack<T, Container>::top()
{
	return (this->_stack.back());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::value_type const &	MutantStack<T, Container>::top() const
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
