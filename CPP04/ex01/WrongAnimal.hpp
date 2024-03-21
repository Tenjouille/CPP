/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:12 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 14:10:57 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
    std::string _type;
public:
    std::string getType(void) const;
    void        makeSound(void) const;

    // Cannonic Form 
    WrongAnimal();
    WrongAnimal(WrongAnimal const & src);
    ~WrongAnimal();

    WrongAnimal& operator=(WrongAnimal const & hrs);
};

#endif
