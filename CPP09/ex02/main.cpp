/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:28:03 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/20 13:29:22 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>

int	main(int ac, char **av)
{
	PmergeMe	fja;
	try
	{
		fja.parsing(ac, av);
		fja.execution();
	}
	catch(const std::string msg)
	{
		std::cerr << msg << '\n';
	}
	return (0);
}


