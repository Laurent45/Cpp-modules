/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:13:50 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/18 11:35:10 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"
#include <iostream>

int main(void)
{
	Data data = {42, 'c', 42.4242f, 2424.2424};
	
	Data * ret = deserialize(serialize(&data));
	
	if (ret == &data)
	{
		std::cout << ret << " == " << &data << std::endl;;
		std::cout << "id: " << ret->id
				  << "\nc: " << ret->c
				  << "\nf: " << ret->f
				  << "\nd: " << ret->d << std::endl;
	}
	
	return (0);
}
