/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:54:07 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/06 18:02:40 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Materia.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void	test1()
{
	std::cout << "////////////// 1 : WRONG MATERIA CREATION//////////////" << std::endl;
	I_MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	I_Character* me = new Character("me");
	std::cout << "Trying to create a wrong materia :" << std::endl << std::endl;
	std::cout << "Spagghetti materia = " << src->createMateria("spaghetti") << std::endl;
	delete me;
	delete src;
}

void	test2()
{
	std::cout << "////////////// 2 : WRONG SLOT USE//////////////" << std::endl;
	I_MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	I_Character* me = new Character("me");
	A_Materia* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	I_Character* bob = new Character("bob");
	std::cout << "Trying to use inventory[9] :" << std::endl;
	me->use(9, *bob);
	std::cout << std::endl << "Trying to use inventory[-1] :" << std::endl;
	me->use(-1, *bob);
	delete bob;
	delete me;
	delete src;
}

void	test3()
{
	std::cout << "////////////// 3 : NO MORE PLACE IN MATERIASOURCE//////////////" << std::endl;
	std::cout << "Trying to overfill MateriaSource :" << std::endl << std::endl;
	I_MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	I_Character* me = new Character("me");
	A_Materia* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	I_Character* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	delete bob;
	delete me;
	delete src;
}

void	test4()
{
	std::cout << "////////////// 4 : NO MORE PLACE IN CHARACTER'S INVENTORY//////////////" << std::endl;
	std::cout << "Trying to overfill the character's inventory :" << std::endl << std::endl;
	I_MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	I_Character* me = new Character("me");
	A_Materia* tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	I_Character* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	delete bob;
	delete me;
	delete src;
}

void	test5()
{
	std::cout << "////////////// 5 : UNEQUIP AN EMPTY AND NON EXISTING INVENTORY SLOT//////////////" << std::endl;
	I_Character* me = new Character("me");
	
	std::cout << "Trying to unequip an empty inventory slot :" << std::endl;
	me->unequip(0);
	std::cout << std::endl;
	std::cout << "Trying to unequip a non existing inventory slot (-1) :" << std::endl;
	me->unequip(-1);
	delete me;
}

void	test6()
{
	std::cout << "////////////// 6 : FILL INVENTORY, THEN EMPTY IT, THEN REFILL IT (CHECK LEAKS)//////////////" << std::endl;
	I_MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	I_Character* me = new Character("me");
	A_Materia* tmp0;
	A_Materia* tmp1;
	A_Materia* tmp2;
	A_Materia* tmp3;
	std::cout << "Filling Inventory..." << std::endl << std::endl;
	tmp0 = src->createMateria("ice");
	tmp1 = src->createMateria("ice");
	tmp2 = src->createMateria("cure");
	tmp3 = src->createMateria("cure");
	me->equip(tmp0);
	me->equip(tmp1);
	me->equip(tmp2);
	me->equip(tmp3);
	std::cout << "Using full inventory..." << std::endl << std::endl;
	I_Character* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	std::cout << std::endl << "Emptying Inventory..." << std::endl << std::endl;
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	delete tmp0;
	delete tmp1;
	delete tmp2;
	delete tmp3;
	std::cout << std::endl << "Using empty inventory..." << std::endl << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	std::cout << std::endl << "Filling Inventory once again..." << std::endl << std::endl;
	tmp0 = src->createMateria("cure");
	tmp1 = src->createMateria("cure");
	tmp2 = src->createMateria("ice");
	tmp3 = src->createMateria("ice");
	me->equip(tmp0);
	me->equip(tmp1);
	me->equip(tmp2);
	me->equip(tmp3);
	std::cout << "Using full inventory..." << std::endl << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	delete bob;
	delete me;
	delete src;
}

void	test_hub(void)
{
	std::cout << std::endl << std::endl << std::endl << std::endl;
	test1();
	std::cout << std::endl << std::endl << std::endl << std::endl;
	test2();
	std::cout << std::endl << std::endl << std::endl << std::endl;
	test3();
	std::cout << std::endl << std::endl << std::endl << std::endl;
	test4();
	std::cout << std::endl << std::endl << std::endl << std::endl;
	test5();
	std::cout << std::endl << std::endl << std::endl << std::endl;
	test6();
}

int main()
{
	A_Materia *test = new Cure();
	std::cout << test->getType() << std::endl;
	delete test;
	std::cout << "//////////////TEST DU SUJET//////////////" << std::endl;
	I_MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	I_Character* me = new Character("me");
	A_Materia* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	I_Character* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	test_hub();
	return 0;
}