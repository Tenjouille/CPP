/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:31:30 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/09 16:03:51 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	doubleInt(int& n)
{
	n *= 2;
}

void	ft_toupper(char& c)
{
	c = toupper(c);
}

void	hugediff(double& n)
{
	n += 0.01;
}

int	main()
{
	int		Test1[11] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
	char	Test2[13] = {'s', 'a', 'y', ' ', 'i', 't', ' ', 'l', 'o', 'u', 'd', 'e', 'r'};
	double	Test3[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	////////////////INT////////////////
	for (int i = 0; i < 11; i++)
		std::cout << Test1[i] << ' ';
	std::cout  << " -> ";
	::iter(Test1, 11, doubleInt);
	for (int i = 0; i < 11; i++)
		std::cout << Test1[i] << ' ';
	std::cout << std::endl << std::endl;
	////////////////CHAR////////////////
	for (int i = 0; i < 13; i++)
		std::cout << Test2[i];
	std::cout  << " -> ";
	::iter(Test2, 13, ft_toupper);
	for (int i = 0; i < 13; i++)
		std::cout << Test2[i];
	std::cout << std::endl << std::endl;
	////////////////DOUBLE////////////////
	for (int i = 0; i < 11; i++)
		std::cout << Test3[i] << ' ';
	std::cout  << " -> ";
	::iter(Test3, 11, hugediff);
	for (int i = 0; i < 11; i++)
		std::cout << Test3[i] << ' ';
	std::cout << std::endl << std::endl;
	return (0);
}
