/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:01:57 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 12:33:13 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <iostream>

class ClapTrap
{
protected:
    std::string  _name;
    unsigned int    _hp;
    unsigned int    _ep;
    unsigned int    _ad;
public:
    void    attack(std::string const & target);
    void    takeDamage(unsigned int const amount);
    void    beRepaired(unsigned int const amount);
    ClapTrap(std::string const name);
    // For tests
    void	printInfos() const;
    // Setters & getters
    unsigned int    getHP(void) const;
    unsigned int    getEP(void) const;
    unsigned int    getAD(void) const;
    void            setHP(unsigned int const hp);
    void            setEP(unsigned int const ep);
    void            setAD(unsigned int const ad);
    // Canonic form
    ClapTrap();
    ClapTrap(ClapTrap const & src);
    ClapTrap& operator=(ClapTrap const & hrs);
    ~ClapTrap();
};

#endif

