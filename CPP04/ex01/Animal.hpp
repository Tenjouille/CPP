/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:41 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 22:01:45 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
    std::string _type;
public:
    std::string     getType(void) const;
    virtual void    makeSound(void) const;

    // Cannonic Form 
    Animal();
    Animal(Animal const & src);
    virtual ~Animal();

    Animal& operator=(Animal const & hrs);
};

#endif
