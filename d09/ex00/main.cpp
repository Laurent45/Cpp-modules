/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:15:22 by lfrederi          #+#    #+#             */
/*   Updated: 2023/07/08 17:08:53 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

// TODO(): if _ref is empty

int main(int argc, char const *argv[])
{
    (void) argv;
    if (argc != 2)
    {
        std::cout << "Usage: ./btc <input file>" << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange btc;
        btc.calculateRateExchange(argv[1]);
    }
    catch(std::exception & e)
    {
        std::cout << e.what();
        return 1;
    }

    return 0;
}
