
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal 
{
public:
    void    makeSound(void) const;

    //Cannonic Form
    WrongCat();
    WrongCat(WrongCat const & src);
    ~WrongCat();

    WrongCat& operator=(WrongCat const & hrs);
};

#endif
