/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:10:51 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/13 16:23:26 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <string.h>

int	main(int ac, char **av)
{
	PhoneBook	repertory;
	
	(void) av;
	if (ac != 1)
		return (1);
	std::cout << "\e[1;1H\e[2J" << std::endl;
	std::cout << YELLOW << "Welcome to the YELLOW PAGES™ " << std::endl;
	repertory.ft_new_order(0);
	return (0);
}
