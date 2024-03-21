/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:02:05 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/19 19:12:19 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	Wall("Wall");
	ClapTrap	RobotCop("RobotCop");

	Wall.printInfos();
	RobotCop.attack("Humans");
	RobotCop.printInfos();
	for (int i = 0; i < 10; i++)
		RobotCop.beRepaired(0);
	RobotCop.printInfos();
	RobotCop.attack("Wall");
	Wall.takeDamage(5);
	Wall.takeDamage(1000);
	Wall.beRepaired(0);
	RobotCop.takeDamage(1000);
	RobotCop.beRepaired(0);
	return (0);	
}