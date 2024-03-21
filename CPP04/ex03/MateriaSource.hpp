/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:16:21 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 17:06:00 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "I_MateriaSource.hpp"

class MateriaSource : public I_MateriaSource
{
private:
	A_Materia**	_materia;
public:
	MateriaSource();
	MateriaSource(MateriaSource const & src);
	virtual ~MateriaSource();

	MateriaSource const &	operator=(MateriaSource const & src);

	virtual void learnMateria(A_Materia*);
	virtual A_Materia* createMateria(std::string const & type);
};

#endif