/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:44 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 13:20:04 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string	A_Animal::getType(void) const
{
	return (this->_type);
}

A_Animal&	A_Animal::operator=(A_Animal const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

A_Animal::A_Animal(A_Animal const & src) : _type(src._type)
{
	std::cout << "🐾\tCopy constructor called" << std::endl;
	return ;
}

A_Animal::A_Animal() : _type("Animal")
{
	std::cout << "🐾\tDefault constructor called" << std::endl;
	return ;
}

A_Animal::~A_Animal()
{
	std::cout << "🐾\tDestructor called" << std::endl;
	return ;
}
