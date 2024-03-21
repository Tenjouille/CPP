/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:47 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 14:18:00 by tbourdea         ###   ########.fr       */
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
		this->_type = rhs._type;
	return (*this);
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << "🐱\tCopy constructor called" << std::endl;
	*this = src;
	return ;
}

Cat::Cat() : Animal()
{
	std::cout << "🐱\tDefault constructor called" << std::endl;
	_type = "Cat";
	return ;
}

Cat::~Cat()
{
	std::cout << "🐱\tDestructor called" << std::endl;
	return ;
}
