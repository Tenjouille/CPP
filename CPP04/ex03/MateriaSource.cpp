/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:26:18 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 18:51:38 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _materia(new A_Materia*[4])
{
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src) : _materia(new A_Materia*[4])
{
	for (size_t i = 0; i < 4; i++)
		if (src._materia[i])
			this->_materia[i] = src._materia[i];
		else
			this->_materia[i] = NULL;
	
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
		if (this->_materia[i])
			delete _materia[i];
	delete[] _materia;
}

MateriaSource const &	MateriaSource::operator=(MateriaSource const & src)
{
	if (this != &src)
	{
		for(int i = 0; i < 4; i++)
			if (this->_materia[i])
				delete _materia[i];
		for(int i = 0; i < 4; i++)
			if (src._materia[i])
				this->_materia[i] = src._materia[i];
			else
				this->_materia[i] = NULL;
	}
	return(*this);
}

void	MateriaSource::learnMateria(A_Materia* m)
{
	int	i = 0;
	while (i < 4 && this->_materia[i])
		i++;
	if (i < 4)
		this->_materia[i] = m;
	else
	{
		std::cout << "MateriaSource is full, impossible to add " << m->getType() << std::endl;
		delete m;
	}
}

A_Materia*	MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4 && this->_materia[i]; i++)
		if (type == _materia[i]->getType())
			return (_materia[i]->clone());
	return (0);
}