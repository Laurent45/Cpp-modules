/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:52:54 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/01 14:00:46 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(void)
{
	Point a(0, 0);
	Point b(1, 2);
	Point c(2, 0);
	Point point(1, 0);
	std::cout << (bsp(a, b, c, point) ? "true" : "false") << std::endl;

	Point aa(1, 5);
	Point bb(12.2f, 2);
	Point cc(4.32f, 0);
	Point p(1.5f, 1.5f);
	std::cout << (bsp(aa, bb, cc, p) ? "true" : "false") << std::endl;

	Point aaa(0, 0);
	Point bbb(2.2f, 2);
	Point ccc(-4.32f, 10);
	Point pp(1.5f, 1.5f);
	std::cout << (bsp(aaa, bbb, ccc, pp) ? "true" : "false") << std::endl;

	Point aaaa(0, 0);
	Point bbbb(2.2f, 2);
	Point cccc(-4.32f, 10);
	Point ppp(2.2f, 2.0f);
	std::cout << (bsp(aaaa, bbbb, cccc, ppp) ? "true" : "false") << std::endl;

	return 0;
}
