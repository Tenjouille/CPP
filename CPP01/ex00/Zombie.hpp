/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:53:10 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/14 10:44:36 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
private:
	std::string	_name;
public:
// 	std::string	get_name(void);
// 	void		set_name(std::string arg);
	void		announce(void);
	Zombie(std::string name);
	~Zombie();
};

Zombie		*newZombie(std::string name);
void		randomChump(std::string name);