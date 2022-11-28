/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:15:23 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/28 12:01:27 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <vector>

class Span
{
	private:
		unsigned int _size;
		std::vector<int> _store;

		Span(void);

	public:
		~Span(void);
		Span(Span const & copy);
		Span &	operator=(Span const & rhs);

		Span(unsigned int size);

		void			addNumber(int number);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class SpanIsFullException : public std::exception
		{
			public:
				virtual char const * what() const throw();
		};

		class SpanIsLowException : public std::exception
		{
			public:
				virtual char const * what() const throw();
		};


		template<typename InputIterator>
		void	addNumber(InputIterator first, InputIterator last)
		{
			try {
				for (; first != last; first++)
					addNumber(*first);
			} catch (std::exception & e) {
				std::cerr << e.what() << "\n";
			}
		}

};

#endif
