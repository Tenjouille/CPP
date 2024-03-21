/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:46:42 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/31 19:36:50 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default constructor called for Serializer" << std::endl;
}

Serializer::Serializer(Serializer const & src)
{
	(void) src;
	std::cout << "Copy constructor called for Serializer" << std::endl;
}

Serializer&	Serializer::operator=(Serializer const & rhs)
{
	(void) rhs;
	std::cout << "Assignment operator called for Serializer" << std::endl;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Destructor called for Serializer" << std::endl;
}

uintptr_t	Serializer::serialize(t_Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

t_Data*	Serializer::deserialize(uintptr_t ptr)
{
	return (reinterpret_cast<t_Data*>(ptr));
}