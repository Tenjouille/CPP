/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:52 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/30 18:26:30 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void	Dog::makeSound(void) const
{
	std::cout << "WOOOF !" << std::endl;
}

Dog&	Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << "🐶\tConstructor called" << std::endl;
	*this = src;
	return ;
}

Dog::Dog() : Animal()
{
	std::cout << "🐶\tConstructor called" << std::endl;
	_type = "Dog";
	return ;
}

Dog::~Dog()
{
	std::cout << "🐶\tDestructor called" << std::endl;
	return ;
}


