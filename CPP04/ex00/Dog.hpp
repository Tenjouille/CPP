/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:57 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 14:03:58 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>

class Dog : public Animal
{
public:
    virtual void        makeSound(void) const;

    //Cannonic Form
    Dog();
    Dog(Dog const & src);
    virtual ~Dog();

    Dog& operator=(Dog const & hrs);
};

#endif

