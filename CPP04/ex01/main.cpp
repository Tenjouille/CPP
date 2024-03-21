/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:59 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 22:05:18 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

#define LEN 10

int main()
{
	const Animal* meta[LEN];

	for(int i = 0; i < LEN / 2; i++)
		meta[i] = new Dog();
	for(int i = LEN / 2; i < LEN; i++)
		meta[i] = new Cat();
	for(int i = 0; i < LEN; i++)
		meta[i]->makeSound();
	for(int i = 0; i < LEN; i++)
		delete meta[i];
	std::cout << std::endl << std::endl;
	Dog	basic;
	{
		Dog tmp = basic;
	}
	basic.makeSound();
	
	return (0);	
}

