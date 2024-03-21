/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:32:27 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 17:07:20 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "A_Materia.hpp"

class	Cure : public A_Materia
{
public:
	Cure();
	Cure(Cure const & src);
	Cure(std::string const & type);
	Cure&	operator=(Cure const & cpy);
	virtual ~Cure();
	virtual A_Materia*	clone()const;
	virtual void		use(I_Character& target);
};

#endif