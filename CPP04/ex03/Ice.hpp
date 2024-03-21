/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:22:17 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 17:03:03 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "A_Materia.hpp"

class	Ice : public A_Materia
{
public:
	Ice();
	Ice(Ice const & src);
	Ice&	operator=(Ice const & cpy);
	virtual ~Ice();
	virtual A_Materia*	clone()const;
	virtual void		use(I_Character& target);
};

#endif