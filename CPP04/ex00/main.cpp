/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:59 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 21:34:34 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;

	const WrongAnimal*	Wmeta = new WrongAnimal();
	const WrongAnimal*		Wi = new WrongCat();
	const WrongCat*			Wj = new WrongCat();
	std::cout << Wmeta->getType() << " " << std::endl;
	std::cout << Wi->getType() << " " << std::endl;
	std::cout << Wj->getType() << " " << std::endl;
	Wmeta->makeSound();
	Wi->makeSound();
	Wj->makeSound();
	delete Wmeta;
	delete Wi;
	delete Wj;
		return (0);	
}

