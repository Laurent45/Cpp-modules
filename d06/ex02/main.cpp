/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:19:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/18 12:28:45 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	Base * p = generate();
	Base & ref = *p;

	identify(p);
	identify(ref);

	delete p;

	return (0);
}
