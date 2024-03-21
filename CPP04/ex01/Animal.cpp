/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:44 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 14:12:22 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout << "*Random animal sound*" << std::endl; 
}

Animal&	Animal::operator=(Animal const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Animal::Animal(Animal const & src) : _type(src._type)
{
	std::cout << "🐾\tCopy constructor called" << std::endl;
	return ;
}

Animal::Animal() : _type("Animal")
{
	std::cout << "🐾\tDefault constructor called" << std::endl;
	return ;
}

Animal::~Animal()
{
	std::cout << "🐾\tDestructor called" << std::endl;
	return ;
}
