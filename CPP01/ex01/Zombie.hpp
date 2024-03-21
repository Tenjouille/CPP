/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:53:10 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/14 10:47:28 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <stdlib.h>

class Zombie
{
private:
	std::string	_name;
public:
	void		set_name(std::string arg);
	void		announce(void);
	Zombie();
	~Zombie();
};

Zombie		*zombieHorde(int N, std::string name);

#endif