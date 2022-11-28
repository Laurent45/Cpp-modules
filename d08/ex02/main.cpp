/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:56:45 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/28 12:36:03 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <list>

int main()
{
	{
		MutantStack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}

	std::cout << '\n';

	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << '\n';

	{
		MutantStack<int, std::list<int> > mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	
	std::cout << '\n';

	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << '\n';

		MutantStack<int> stk(mstack);
		it = stk.begin();
		ite = stk.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << '\n';

		std::stack<int> s(mstack);
		while (!s.empty())
		{
			std::cout << s.top() << std::endl;
			s.pop();
		}
		std::cout << '\n';

		MutantStack<int> tmp;
		tmp.push(5);
		tmp.push(17);
		it = tmp.begin();
		ite = tmp.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << '\n';

	}

	{
		MutantStack<int> mStack;
		mStack.pop();

		std::stack<int> stack;
		stack.pop();
	}

		
	return 0;
}
