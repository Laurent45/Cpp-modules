/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:32:50 by lfrederi          #+#    #+#             */
/*   Updated: 2023/09/19 21:18:24 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

/****************
 * CANONICAL FORM
 ****************/

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const & copy) : _vec(copy._vec), _lst(copy._lst) {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
  if (this != &rhs)
  {
    _vec = rhs._vec;
    _lst = rhs._lst;
  }
  return (*this);
}

PmergeMe::~PmergeMe(void) {}

/******************************************************************************/

/****************
 * CONSTRUCTOR
 ****************/

PmergeMe::PmergeMe(std::string numbers)
{
  // Skip the last space
  std::string::reverse_iterator rit=numbers.rbegin();
  for (; rit!=numbers.rend(); ++rit)
  {
    if (!std::isspace(*rit))
      break ;
  }

  numbers = numbers.substr(0, &(*rit) - &(*numbers.begin()) + 1);
  
  std::istringstream stream(numbers);
  int val;
  while (stream.good())
  {
    stream >> val;
    if (stream.fail() || val < 0)
      throw std::runtime_error("An arg in integer list is invalid or negative");
    _vec.push_back(val);
    _lst.push_back(val);
  }
}

/******************************************************************************/

/****************
 * PUBLIC METHODS
 ****************/

void  PmergeMe::run()
{
  sortVector(0, _vec.size() - 1);
}

/******************************************************************************/

/****************
 * PRIVATE METHODS
 ****************/

void  PmergeMe::sortVector(int right, int left)
{
  if (left - right > K)
  {
    int middle = (left + right) / 2;
    sortVector(right, middle);
    sortVector(middle + 1, left);
    mergeVector(right, middle, left);
  }
  else
  {
    insertionSortVector(right, left);
  }
}

void  PmergeMe::mergeVector(int right, int middle, int left)
{
  std::cout << "mergeVector: " << right << " : " << middle << " : "<< left<< std::endl;
}

void  PmergeMe::insertionSortVector(int right, int left)
{
  std::cout << "insertionSort: " << right << " : " << left << std::endl;
  
}







