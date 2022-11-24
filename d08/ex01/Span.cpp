/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:58:59 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/24 15:14:44 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <limits.h>

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
Span::Span(void) : _size(0) {}

Span::~Span(void) {}

Span::Span(Span const & copy) : _size(copy._size), _store(copy._store) {}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs) {
		_size = rhs._size;
		_store.clear();
		_store = rhs._store;
	}

	return (*this);
}

// Constructors
Span::Span(unsigned int size) : _size(size) {}

// Members methods
void	Span::addNumber(int number)
{
	if (this->_store.size() == _size)
		throw Span::SpanIsFullException();

	this->_store.push_back(number);
}

unsigned int	Span::shortestSpan()
{
	if (this->_store.size() == 1 || this->_store.empty())
		throw Span::SpanIsLowException();

	std::vector<int> tmp(_store);
	std::sort(tmp.begin(), tmp.end());
	unsigned int shortest = UINT_MAX;
	
	for (std::vector<int>::const_iterator it = tmp.begin(); it != tmp.end() - 1; ++it)
		shortest = std::min(shortest, static_cast<unsigned int>(*(it + 1)) - static_cast<unsigned int>(*it));
	return (shortest);
}

unsigned int		Span::longestSpan()
{
	if (this->_store.size() == 1 || this->_store.empty())
		throw Span::SpanIsLowException();

	unsigned int min = *(std::min_element(this->_store.begin(), this->_store.end()));
	unsigned int max = *(std::max_element(this->_store.begin(), this->_store.end()));

	return (max - min);
}

char const *	Span::SpanIsFullException::what() const throw()
{
	return "Exception: Span is full";
}

char const *	Span::SpanIsLowException::what() const throw()
{
	return "Exception: Span is low";
}
