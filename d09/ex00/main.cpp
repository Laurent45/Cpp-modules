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

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc <input file>" << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange btc;
        btc.loadDataBase();
        btc.calculateRateExchange(argv[1]);
    }
    catch(std::exception & e)
    {
        return 1;
    }

    return 0;
}
