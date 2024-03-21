/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:53:59 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/14 10:44:26 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// void	Zombie::set_name(std::string name)
// {
// 	this->_name = name;
// }

// std::string	Zombie::get_name(void)
// {
// 	return (this->_name);
// }

void	Zombie::announce(void)
{
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string	name) : _name(name)
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << "\"GRAAAAaaah !\" " << this->_name << " just died. It'll never hurt you again." << std::endl;
}