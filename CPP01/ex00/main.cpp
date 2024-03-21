/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:10:44 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/14 10:54:25 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie		*Larry = newZombie("Larry");
	Zombie		Berny("Berny");
	Zombie		Johnny("Johnny");
	// std::string	tmp;

	randomChump("Rick");
	// std::cout << Larry->get_name() << " is a healthy zombie !" << std::endl;
	Larry->announce();
	// tmp = Larry->get_name();
	delete Larry;
	Berny.announce();
	// std::cout << "OK, " << tmp << " died... But " << Berny.get_name() << " is still up, right ?" << std::endl;
	return (0);
}