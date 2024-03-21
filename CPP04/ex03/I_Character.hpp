/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   I_Character.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:04:37 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 17:33:37 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_CHARACTER_HPP
# define I_CHARACTER_HPP

# include <iostream>

class	A_Materia;

class	I_Character
{
public:
	virtual	~I_Character() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(A_Materia* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, I_Character& target) = 0;
};

#endif
