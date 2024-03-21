/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:51:03 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 20:00:42 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

void	ScavTrap::attack(std::string const & target)
{
	if (!this->_hp || !this->_ep)
	{
		std::cout << this->_name << " has no ";
		if (!this->_hp)
		{
			std::cout << "Hit points";
			if (!this->_ep)
				std::cout << " and no ";
		}
		if (!this->_ep)
			std::cout << "Energy points";
		std::cout << ". It cannot do anything" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " uses tackle on " << target << ", dealing him " << this->_ad <<  " points of damage !" << std::endl; 
		this->_ep -= 1;
	}
}

void	ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << this->_name << " is in Gate keeper mode." << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
	std::cout << "\033[33m" << "ClapTrap " << this->_name << " appears to be a ScavTrap !!" << "\033[0m" << std::endl;
	_hp = 100;
	_ep = 50;
	_ad = 20;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
	std::cout << "\033[33m" << "ClapTrap " << src._name << " appears to be a ScavTrap !!" << "\033[0m" << std::endl;
	return ;
}

ScavTrap::ScavTrap()
{
	_name = "ScavTrap";
	std::cout << "\033[33m" << "ClapTrap " << this->_name << " appears to be a ScavTrap !!" << "\033[0m" << std::endl;
	_hp = 100;
	_ep = 50;
	_ad = 20;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[33m" << "ScavTrap " << this->_name << "'s request to become a ClapTrap has been accepted !!" << "\033[0m" << std::endl;
	return ;
}


