/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Materia.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:08:55 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/06 18:15:19 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Materia.hpp"

A_Materia::A_Materia(void) : _type("")
{
	return ;
}

A_Materia::A_Materia(A_Materia const & src)
{
	this->_type = src._type;
}

A_Materia::A_Materia(std::string const & type) : _type(type)
{
	return ;
}

A_Materia::~A_Materia(void)
{
	return ;
}

A_Materia&	A_Materia::operator=(A_Materia const & cpy)
{
	if (this != &cpy)
		this->_type = cpy._type;
	return (*this);
}

std::string const &  A_Materia::getType() const
{
	return (this->_type);
}
