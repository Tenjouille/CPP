/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:01:52 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 12:26:02 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	ClapTrap::printInfos() const
{
	std::cout << "ClapTrap " << this->_name << "'s got " << this->_hp << " hit points, " << this->_ep << " energy points and " << this->_ad << " attack damages." << std::endl;
}

unsigned int	ClapTrap::getHP() const
{
	return (this->_hp);
}

unsigned int	ClapTrap::getEP() const
{
	return (this->_ep);
}

unsigned int	ClapTrap::getAD() const
{
	return (this->_ad);
}

void	ClapTrap::setHP(unsigned int const hp)
{
	this->_hp = hp;
}

void	ClapTrap::setEP(unsigned int const ep)
{
	this->_ep = ep;
}

void	ClapTrap::setAD(unsigned int const ad)
{
	this->_ad = ad;
}

void	ClapTrap::beRepaired(unsigned int const ammount)
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
		this->_ep--;
		this->_hp += ammount;
		std::cout << "ClapTrap " << this->_name << " regained " << ammount << " Hit points and has now " << this->_hp << " hp." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int const ammount)
{
	if (ammount >= this->_hp)
		this->_hp = 0;
	else
		this->_hp -= ammount;
	std::cout << "ClapTrap " << this->_name << " took " << ammount << " points of damage and has now " << this->_hp << " hp." << std::endl;
}

void	ClapTrap::attack(std::string const & target)
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
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_ad <<  " points of damage !" << std::endl; 
		this->_ep -= 1;
	}
}

ClapTrap&	ClapTrap::operator=(ClapTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
	std::cout << "\033[32m" << "ClapTrap " << src._name << " has been created" << "\033[0m" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "\033[32m" << "ClapTrap " << this->_name << " has been created" << "\033[0m" << std::endl;
	return ;
}

ClapTrap::ClapTrap() : _hp(10), _ep(10), _ad(0)
{
	_name = "ClapTrap";
	std::cout << "\033[32m" << "ClapTrap " << this->_name << " has been created" << "\033[0m" << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[32m" << "ClapTrap " << this->_name << " has been destroyed" << "\033[0m" << std::endl;
	return ;
}


