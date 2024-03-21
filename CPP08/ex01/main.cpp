/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:11:28 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/05 11:26:18 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	std::vector<int>	tab;
	Span				rand_sp(10000);

	std::cout << "===================| 10K ENTRIES |===================" << std::endl;
	srand(time(NULL));
	for(int i = 0; i < 10000; i++)
	{
		int	random = rand();
		tab.push_back(random);
	}
	rand_sp.addNumber(tab);
	std::cout << "Shortest span : " << rand_sp.shortestSpan() << std::endl;
	std::cout << "Longest span : " << rand_sp.longestSpan() << std::endl;
	std::cout << "===================| 5 ENTRIES |===================" << std::endl;
	Span sp = Span(5);
	sp.addNumber(rand());
	sp.addNumber(rand());
	sp.addNumber(rand());
	sp.addNumber(rand());
	sp.addNumber(rand());
	sp.print();
	std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	std::cout << "===================| TOO MANY ENTRIES |===================" << std::endl;
	Span	empty_sp;
	try
	{
		empty_sp.addNumber(0);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		empty_sp.shortestSpan();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return (0);
// }
