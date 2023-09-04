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

#include <iostream>
#include "RPN.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./RPN <RPN expression>" << std::endl;
        return 1;
    }

    RPN rpn;
    rpn.calculate(argv[1]);

    return 0;
}
