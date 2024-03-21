/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:39:12 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/05 11:29:39 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		std::cout << "====================|TEST WITH MY MUTANT STACK|====================" << std::endl;
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
		MutantStack<int>::const_iterator const ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "===========|TEST WITH A CONTAINER WITH INCLUDES ITERATORS|===========" << std::endl;
		std::list<int> lstack;
		lstack.push_back(5);
		lstack.push_back(17);
		std::cout << lstack.back() << std::endl;
		lstack.pop_back();
		std::cout << lstack.size() << std::endl;
		lstack.push_back(3);
		lstack.push_back(5);
		lstack.push_back(737);
		lstack.push_back(0);
		std::list<int>::iterator it = lstack.begin();
		std::list<int>::iterator const ite = lstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	// {
	// 	std::cout << "===========|TEST WITH A BASIC STACK|===========" << std::endl;
	// 	std::stack<int> lstack;
	// 	lstack.push(5);
	// 	lstack.push(17);
	// 	std::cout << lstack.top() << std::endl;
	// 	lstack.pop();
	// 	std::cout << lstack.size() << std::endl;
	// 	lstack.push(3);
	// 	lstack.push(5);
	// 	lstack.push(737);
	// 	lstack.push(0);
	// 	std::list<int>::iterator it = lstack.begin();
	// 	std::list<int>::iterator const ite = lstack.end();
	// 	++it;
	// 	--it;
	// 	while (it != ite)
	// 	{
	// 		std::cout << *it << std::endl;
	// 		++it;
	// 	}
	// }
	return (0);
}


