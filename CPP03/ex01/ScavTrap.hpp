/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:51:06 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 12:31:56 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    void    attack(std::string const & target);
    void    guardGate() const;
    ScavTrap(std::string const name);
    // Cannonic form
    ScavTrap();
    ScavTrap(ScavTrap const & src);
    ScavTrap& operator=(ScavTrap const & hrs);
    ~ScavTrap();
};

#endif

