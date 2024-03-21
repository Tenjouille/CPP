/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:11:14 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 21:10:27 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : I_Character(), _name(""), _inventory(new A_Materia*[4])
{
	for(int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : I_Character(), _name(name), _inventory(new A_Materia*[4]) 
{
	for(int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const & src) : _name(src._name)
{
	for(int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character::~Character(void)
{
	for(int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete _inventory[i];
	delete[] _inventory;
}

Character&	Character::operator=(Character const & cpy)
{
	if (this != &cpy)
	{
		for(int i = 0; i < 4; i++)
			if (this->_inventory[i])
				delete _inventory[i];
		for(int i = 0; i < 4; i++)
			if (cpy._inventory[i])
				this->_inventory[i] = cpy._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
	}
	return(*this);
}

std::string const &	Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(A_Materia* m)
{
	int	i = 0;
	
	if (!m)
	{
		std::cout << "This Materia doesn't exist then can't be added to " << this->_name << "'s inventory." << std::endl;
		return ;	
	}
	while ( i < 4 && this->_inventory[i])
		i++;
	if (i < 4)
		this->_inventory[i] = m;
	else
	{
		std::cout << this->_name << "'s inventory is full, impossible to add " << m->getType() << std::endl;
		delete m;
	}
}

void	Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		std::cout << idx << " isn't a valid inventory slot" << std::endl;
	else if (!this->_inventory[idx])
		std::cout << idx << " is an empty inventory slot" << std::endl;
	else
		this->_inventory[idx] = NULL;
}

void	Character::use(int idx, I_Character& target)
{
	if (idx > 3 || idx < 0)
		std::cout << this->_name << "'s inventory's slot number " << idx << " doesn't exist. There are only 4 slot in his inventory." << target.getName() << std::endl;
	else if (!this->_inventory[idx])
		std::cout << this->_name << "'s inventory's slot number " << idx << " is empty. He can't use any materia on " << target.getName() << std::endl;
	else
		this->_inventory[idx]->use(target);
}
