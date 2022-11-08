/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:08:35 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/08 10:38:05 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		std::cout << "Usage: ./HarlFilter <alert_level>" << std::endl;
	else
	{
		Harl harl;

		harl.complainFilter(argv[1]);
	}

	return (0);
}
