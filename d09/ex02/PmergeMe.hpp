/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:34:01 by lfrederi          #+#    #+#             */
/*   Updated: 2023/09/20 11:02:22 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>

#define K 5

class PmergeMe
{
  private:
    std::vector<int>  _vec;
    std::deque<int>   _dqe;

    void  sortVector(int right, int left);
    void  mergeVector(int right, int middle, int left);
    void  insertionSortVector(int right, int left);

    void  sortDeque(int right, int left);
    void  mergeDeque(int right, int middle, int left);
    void  insertionSortDeque(int right, int left);
    
  public:

        PmergeMe(void);
        PmergeMe(PmergeMe const & copy);
        PmergeMe & operator=(PmergeMe const & rhs);
        ~PmergeMe(void);

        PmergeMe(std::string numbers);

        void  run();
};



#endif
