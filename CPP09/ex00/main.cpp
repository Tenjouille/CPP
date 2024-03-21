/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:07:11 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/03 15:55:19 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	std::string	err = "Error : path to the second database missing.";
	try
	{
		if (ac != 2)
			throw err;

		BitcoinExchange	csv;
		csv.scan(av[1]);
	}
	catch(std::string msg)
	{
		std::cerr << msg << std::endl;
		return (1);
	}
	return (0);
}
