/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:08:53 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/28 12:00:17 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	
	{
		Span sp = Span(5);
		int t[] = {0, 1, 2, 3, 4};
		sp.addNumber(t, t + 5);
	
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	
	std::cout << '\n';
	
	{
		Span sp = Span(5);
		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
		} catch (std::exception & e) {
			std::cerr << e.what() << '\n';
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	
	std::cout << '\n';
	
	{
		Span sp = Span(5);
		try {
			sp.addNumber(6);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception & e) {
			std::cerr << e.what() << '\n';
		}
	}
	
	std::cout << '\n';
	
	{
		Span sp = Span(5);
		try {
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception & e) {
			std::cerr << e.what() << '\n';
		}
	}
	
	std::cout << '\n';
	
	{
		Span sp = Span(1000000);
		int t[1000000];
	
		for (int i = 0; i < 1000000; i++)
			t[i] = -50000 + i;
	
		sp.addNumber(t, t + 1000000);
	
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return (0);
}
