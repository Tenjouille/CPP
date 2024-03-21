/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Materia.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:56:09 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/06 18:14:49 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <iostream>
# include "I_Character.hpp"

class	A_Materia
{
protected:
	std::string	_type;
	
public:
	A_Materia();
	A_Materia(A_Materia const & src);
	A_Materia(std::string const & type);
	virtual ~A_Materia();

	A_Materia&	operator=(A_Materia const & cpy);

	std::string const &	getType() const;
	virtual A_Materia*	clone()const = 0;
	virtual void		use(I_Character& target) = 0;
};

#endif