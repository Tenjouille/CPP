/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:38:48 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 12:39:21 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    void    highFivesGuys(void) const;
    FragTrap(std::string const name);
    // Cannonic Form
    FragTrap();
    FragTrap(FragTrap const & src);
    FragTrap& operator=(FragTrap const & hrs);
    ~FragTrap();
};

#endif