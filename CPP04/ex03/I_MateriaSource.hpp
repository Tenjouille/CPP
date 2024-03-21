/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   I_MateriaSource.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:05:08 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 17:05:35 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MATERIASOURCE_HPP
# define I_MATERIASOURCE_HPP

# include "A_Materia.hpp"

class I_MateriaSource
{
public:
virtual ~I_MateriaSource() {}
virtual void learnMateria(A_Materia*) = 0;
virtual A_Materia* createMateria(std::string const & type) = 0;
};

#endif