/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:10:44 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/14 10:55:23 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char **av)
{
	Zombie	*horde;
	if (ac == 1)
		std::cout << "0 Zombie rose this time, you are safe... for now..." << std::endl;
	else if (ac == 2)
	{
		horde = zombieHorde(atoi(av[1]), "Random zombie");
		for(int i = 0; i < atoi(av[1]); i++)
			horde[i].announce();
		delete [] horde;
	}
	else if (ac == 3)
	{
		horde = zombieHorde(atoi(av[1]), av[2]);
		for(int i = 0; i < atoi(av[1]); i++)
			horde[i].announce();
		delete [] horde;
	}
	else
		
		std::cout << "Too many arguments" << std::endl;
	return (0);
}