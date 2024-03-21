/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:50 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 23:38:14 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public A_Animal 
{
private:
    Brain*  _brain;
public:
    virtual void    makeSound(void) const;

    //Cannonic Form
    Cat();
    Cat(Cat const & src);
    virtual ~Cat();

    Cat& operator=(Cat const & hrs);
};

#endif
