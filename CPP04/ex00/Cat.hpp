/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:50 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 14:15:29 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal 
{
public:
    virtual void    makeSound(void) const;

    //Cannonic Form
    Cat();
    Cat(Cat const & src);
    virtual ~Cat();

    Cat& operator=(Cat const & hrs);
};

#endif
