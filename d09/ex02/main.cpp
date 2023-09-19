/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:15:22 by lfrederi          #+#    #+#             */
/*   Updated: 2023/09/19 18:07:32 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <sstream>

int main (int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Usage: ./PmergeMe <positive interger list>" << std::endl;
    return 0;
  }

  
  try {
    PmergeMe pmergeMe(argv[1]);
    pmergeMe.run();
  } catch (std::exception & e) {
    std::cout << e.what() << std::endl;
    return (1);
  }


  return (0);
}
