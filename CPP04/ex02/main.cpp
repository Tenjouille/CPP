/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:59 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 22:13:47 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

#define LEN 10

int main()
{
	std::cout << "/////////////////////SAME TEST AS EX01/////////////////////" << std::endl << std::endl;
	const A_Animal* house[LEN];

	for(int i = 0; i < LEN / 2; i++)
		house[i] = new Dog();
	for(int i = LEN / 2; i < LEN; i++)
		house[i] = new Cat();
	for(int i = 0; i < LEN; i++)
		house[i]->makeSound();
	for(int i = 0; i < LEN; i++)
		delete house[i];
	std::cout << std::endl << std::endl<< "/////////////////////SAME TEST AS EX00/////////////////////" << std::endl << std::endl;
	const A_Animal*	meta = new A_Animal; // Can't compile, A_Animal is an abstract class, it can't be instanciate !
	const A_Animal* j = new Dog();
	const A_Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	const WrongAnimal*	Wmeta = new WrongAnimal();
	const WrongAnimal*		Wi = new WrongCat();
	std::cout << Wmeta->getType() << " " << std::endl;
	std::cout << Wi->getType() << " " << std::endl;
	Wi->makeSound();
	Wmeta->makeSound();
	delete Wmeta;
	delete Wi;
	return (0);	
}

