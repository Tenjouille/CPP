/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:33:39 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/05 11:08:44 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	int					n = 5;
	int					x = 11;
	std::vector<int>	vector;
	std::deque<int>		deque;
	std::list<int>		list;

	for (int i = 0; i < 10; i++)
	{
		vector.push_back(i);
		deque.push_back(i);
		list.push_back(i);
	}

	/////////////////// TEST 1 : VALUE : FINDABLE ///////////////////
	if (easyfind(vector, n) < 0)
	{
		std::cerr << "Error : occurence not found." << std::endl;
		return (1);
	}
	std::cout << "Occurence found at index " << easyfind(vector, n) << " in vector." << std::endl;
	std::cout << "Occurence found at index " << easyfind(deque, n) << " in deque." << std::endl;
	std::cout << "Occurence found at index " << easyfind(list, n) << " in list." << std::endl;
	/////////////////// TEST 2 : VALUE NOT FINDABLE ///////////////////
	if (easyfind(vector, x) < 0)
		std::cerr << "Error : occurence not found." << std::endl;
	else
	{
		std::cout << "Occurence found at index : " << easyfind(vector, x) << " in vector." << std::endl;
		std::cout << "Occurence found at index : " << easyfind(deque, x) << " in deque." << std::endl;
		std::cout << "Occurence found at index : " << easyfind(list, x) << " in list." << std::endl;
	}
	/////////////////// TEST 3 : ON A STRING ///////////////////
	if (easyfind(static_cast<std::string>("Hello world"), 'w') < 0)
	{
		std::cerr << "Error : occurence not found." << std::endl;
		return (1);
	}
	std::cout << "Occurence found at index : " << easyfind(static_cast<std::string>("Hello world"), 'w') << " in string." << std::endl;
	return (0);
}
