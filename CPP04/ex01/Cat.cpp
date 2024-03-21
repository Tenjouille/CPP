/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:47 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 22:04:34 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void	Cat::makeSound(void) const
{
	std::cout << "MIAAAAAOU !" << std::endl;
}

Cat&	Cat::operator=(Cat const & rhs)
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

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << "🐱\tCopy constructor called" << std::endl;
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	return ;
}

Cat::Cat() : Animal(), _brain(new Brain)
{
	std::cout << "🐱\tDefault constructor called" << std::endl;
	_type = "Cat";
	return ;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "🐱\tDestructor called" << std::endl;
	return ;
}
