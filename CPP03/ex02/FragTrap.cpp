/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:37:45 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 12:39:54 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "ClapTrap " << this->_name << " is asking for everybody around for a good old high fives !" << std::endl;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	std::cout << "\033[31m" << "ClapTrap " << this->_name << " just lost it and became a FragTrap !!!" << "\033[0m" << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	return ;
}

FragTrap&	FragTrap::operator=(FragTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
	std::cout << "\033[31m" << "ClapTrap " << this->_name << " just lost it and became a FragTrap !!!" << "\033[0m" << std::endl;
	return ;
}

FragTrap::FragTrap()
{
	_name = "FragTrap";
	std::cout << "\033[31m" << "ClapTrap " << this->_name << " just lost it and became a FragTrap !!!" << "\033[0m" << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[31m" << "FragTrap " << this->_name << " managed to calm down and became back a ClapTrap !!!" << "\033[0m" << std::endl;
	return ;
}
