/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:06:25 by juduval           #+#    #+#             */
/*   Updated: 2024/02/06 13:18:46 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	std::string	arg = "";

	if (ac == 1) {
		std::cerr << "Please enter the literal you want to convert." << std::endl;
		return (1);
	}
	arg = av[1];
	ScalarConverter::convert(arg);
	return (0);
}
