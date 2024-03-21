/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:41 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 13:20:28 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class A_Animal
{
protected:
    std::string _type;
public:
    std::string     getType(void) const;
    virtual void    makeSound(void) const = 0 ;

    // Cannonic Form 
    A_Animal();
    A_Animal(A_Animal const & src);
    virtual ~A_Animal();

    A_Animal& operator=(A_Animal const & hrs);
};

#endif
