/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:18:05 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/01 13:52:41 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (point == a || point == b || point == c)
		return (false);
	
	Fixed zero(0);
	Fixed aire_0(a.aire(b, c));
	Fixed aire_1(point.aire(a, b));
	Fixed aire_2(point.aire(b, c));
	Fixed aire_3(point.aire(a, c));
	Fixed total(aire_1 + aire_2 + aire_3);

	std::cout << "main aire = " << aire_0
			  << " => (" << aire_1 << ", " << aire_2 << ", " << aire_3 << ") = "
			  << total << std::endl;

	if (aire_0 == total)
	{
		if (aire_1 != zero && aire_2 != zero && aire_3 != zero)
			return (true);
		return (false);
	}
	return (false);
}
