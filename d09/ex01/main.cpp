/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:15:22 by lfrederi          #+#    #+#             */
/*   Updated: 2023/09/20 11:36:24 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "RPN.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./RPN <RPN expression>" << std::endl;
        return 1;
    }

    RPN rpn;

    try {
      int res = rpn.calculate(argv[1]);
      std::cout << res << std::endl;
    } catch (std::runtime_error const e) {
      std::cout << e.what() << std::endl;
    }

    return 0;
}
