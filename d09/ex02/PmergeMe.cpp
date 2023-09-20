/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:32:50 by lfrederi          #+#    #+#             */
/*   Updated: 2023/09/20 11:05:43 by lfrederi         ###   ########.fr       */
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

PmergeMe::PmergeMe(PmergeMe const & copy) : _vec(copy._vec), _dqe(copy._dqe) {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
  if (this != &rhs)
  {
    _vec = rhs._vec;
    _dqe = rhs._dqe;
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
    _dqe.push_back(val);
  }
}

/******************************************************************************/

/****************
 * PUBLIC METHODS
 ****************/

void  PmergeMe::run()
{
  std::cout << "Vector sort: " << std::endl;
  for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;

  sortVector(0, _vec.size() - 1);

  for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;


  std::cout << "Deque sort: " << std::endl;
  for (std::deque<int>::iterator it = _dqe.begin(); it != _dqe.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;

  sortDeque(0, _dqe.size() - 1);

  for (std::deque<int>::iterator it = _dqe.begin(); it != _dqe.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
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
    insertionSortVector(right, left);
}

void  PmergeMe::mergeVector(int right, int middle, int left)
{
  std::vector<int> rightVec(_vec.begin() + right, _vec.begin() + middle + 1);
  std::vector<int>::const_iterator itR = rightVec.begin();
  std::vector<int> leftVec(_vec.begin() + middle + 1, _vec.begin() + left + 1);
  std::vector<int>::const_iterator itL = leftVec.begin();

  for (int i = right; i < left + 1; i++)
  {
    if (itR == rightVec.end())
    {
      _vec[i] = *itL;
      itL++;
    }
    else if (itL == leftVec.end())
    {
      _vec[i] = *itR;
      itR++;
    }
    else if (*itL > *itR)
    {
      _vec[i] = *itR;
      itR++;
    }
    else 
    {
      _vec[i] = *itL;
      itL++;
    }
  }
}

void  PmergeMe::insertionSortVector(int right, int left)
{
  for (int i = right; i < left; i++)
  {
    int tmp = _vec[i + 1];
    int j = i + 1;
    while (j > right && _vec[j - 1] > tmp)
    {
      _vec[j] = _vec[j - 1];
      j--;
    }
    _vec[j] = tmp;
  }
}

void  PmergeMe::sortDeque(int right, int left)
{
  if (left - right > K)
  {
    int middle = (left + right) / 2;
    sortDeque(right, middle);
    sortDeque(middle + 1, left);
    mergeDeque(right, middle, left);
  }
  else
    insertionSortDeque(right, left);
}

void  PmergeMe::mergeDeque(int right, int middle, int left)
{
  std::deque<int> rightDqe(_dqe.begin() + right, _dqe.begin() + middle + 1);
  std::deque<int>::const_iterator itR = rightDqe.begin();
  std::deque<int> leftDqe(_dqe.begin() + middle + 1, _dqe.begin() + left + 1);
  std::deque<int>::const_iterator itL = leftDqe.begin();

  for (int i = right; i < left + 1; i++)
  {
    if (itR == rightDqe.end())
    {
      _dqe[i] = *itL;
      itL++;
    }
    else if (itL == leftDqe.end())
    {
      _dqe[i] = *itR;
      itR++;
    }
    else if (*itL > *itR)
    {
      _dqe[i] = *itR;
      itR++;
    }
    else 
    {
      _dqe[i] = *itL;
      itL++;
    }
  }
}
void  PmergeMe::insertionSortDeque(int right, int left)
{
  for (int i = right; i < left; i++)
  {
    int tmp = _dqe[i + 1];
    int j = i + 1;
    while (j > right && _dqe[j - 1] > tmp)
    {
      _dqe[j] = _dqe[j - 1];
      j--;
    }
    _dqe[j] = tmp;
  }
}









