/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:52 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 22:03:42 by tbourdea         ###   ########.fr       */
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
	{
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
		this->_type = rhs._type;
	}
	return (*this);
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << "🐶\tCopy constructor called" << std::endl;
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	return ;
}

Dog::Dog() : Animal(), _brain(new Brain)
{
	std::cout << "🐶\tDefault constructor called" << std::endl;
	_type = "Dog";
	return ;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "🐶\tDestructor called" << std::endl;
	return ;
}
