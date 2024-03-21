/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:54:34 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/06 17:22:29 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "I_Character.hpp"
# include "A_Materia.hpp"

class	Character : public I_Character
{
private:
	std::string	_name;
	A_Materia**	_inventory;
public:
	Character();
	Character(Character const & src);
	Character(std::string name);
	virtual	~Character(void);

	Character&	operator=(Character const & cpy);
	
	virtual std::string const & getName() const;
	virtual void	equip(A_Materia* m);
	virtual void 	unequip(int idx);
	virtual void	use(int idx, I_Character& target);
};

#endif