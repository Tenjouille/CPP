/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:50:35 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 20:02:03 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	Wall("Wall");
	ClapTrap	RobotCop("RobotCop");
	ScavTrap	Terminator("Terminator");
	ScavTrap	Tgeorge("Tgeorge");
	FragTrap	Franky("Franky");
	FragTrap	Robot("Robot");

	Franky.highFivesGuys();
	Tgeorge.guardGate();
	Franky.attack("Pirates");
	Franky.takeDamage(100);
	Franky.printInfos();
	Franky.beRepaired(0);
	Robot.beRepaired(42);
	Robot.printInfos();
	Wall.printInfos();
	Terminator.printInfos();
	Tgeorge.attack("Robocop");
	RobotCop.takeDamage(20);
	RobotCop.attack("Humans");
	RobotCop.printInfos();
	Terminator.takeDamage(42);
	for (int i = 0; i < 10; i++)
		Terminator.beRepaired(4);
	for(int i = 0; i < 40; i++)
		Terminator.attack("T-1000");
	Terminator.printInfos();
	Wall.takeDamage(5);
	Wall.takeDamage(1000);
	Wall.beRepaired(0);
	Terminator.takeDamage(1000);
	Terminator.beRepaired(0);
	return (0);	
}

