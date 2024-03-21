/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:13:06 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 14:25:17 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "*Wrong random animal sound*" << std::endl; 
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) : _type(src._type)
{
	std::cout << "!🐾\tCopy constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "!🐾\tDefault constructor called" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "!🐾\tDestructor called" << std::endl;
	return ;
}
