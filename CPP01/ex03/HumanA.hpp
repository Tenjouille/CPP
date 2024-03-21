/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:50:10 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/14 12:18:26 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string	_name;
	Weapon&		_weapon; 
/*
HumanA possede une reference de Weapon 
Car si HumanA est construit avec une Weapon, et que par la suite les attribus de cette weapon change
Sans reference, la weapon de HumanA ne sera pas mise a jour.
*/
public:
	void	attack(void);
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
};

#endif
