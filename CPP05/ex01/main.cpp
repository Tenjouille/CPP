/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:33:34 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/23 13:41:42 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int	main()
{
	std::cout << "//////////////////////////////////////////// Ex00 ////////////////////////////////////////////" << std::endl << std::endl;
	std::cout << "______________________________________________________	   ______________________________________________________" << std::endl;
	std::cout << "______________________________________________________TEST 01______________________________________________________" << std::endl << std::endl;
	std::cout << "1. TEST INCREMENT AND DECREMENT FUNCTIONS" << std::endl;
	Bureaucrat	bureaucrat("Jerry", 12);
	std::cout << bureaucrat;
	while (bureaucrat.getGrade() > 1) 
	{
		bureaucrat.incrGrade();
		std::cout << bureaucrat;
	}
	while (bureaucrat.getGrade() < 150) 
	{
		bureaucrat.decrGrade();
		std::cout << bureaucrat;
	}
	std::cout << std::endl << std::endl;
	std::cout << "______________________________________________________       ______________________________________________________" << std::endl;
	std::cout << "______________________________________________________TEST 02______________________________________________________" << std::endl << std::endl;
	std::cout << "2. TEST WITH OUTRANGE GRADES" << std::endl;
	Bureaucrat	Jerry("Jerry", 0);
	Bureaucrat	John("John", -150);
	Bureaucrat	Josh ("Josh", -999999999999999999);
	Bureaucrat	Jason("Jason", 151);
	Bureaucrat	James("James", 999999999999999999);
	std::cout << Jerry << John << Josh << Jason << James;
	std::cout << std::endl << std::endl;
	std::cout << "______________________________________________________       ______________________________________________________" << std::endl;
	std::cout << "______________________________________________________TEST 03______________________________________________________" << std::endl << std::endl;
	std::cout << "3. TEST WITH VALID GRADES" << std::endl;
	Bureaucrat	Michael("Michael", 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001);
	Bureaucrat	Dwight("Dwight", +00000000000000000000000000000000000000000000000000000000000000000000002);
	Bureaucrat	Kevin("Kevin", 150);
	Bureaucrat	Oscar("Oscar", 99);
	Bureaucrat	Angela(Dwight);
	Dwight.incrGrade();
	std::cout << Michael << Dwight << Kevin << Oscar << Angela;
	std::cout << std::endl << std::endl;
	std::cout << "______________________________________________________	   ______________________________________________________" << std::endl;
	std::cout << "______________________________________________________TEST 04______________________________________________________" << std::endl << std::endl;
	std::cout << "4. TEST INCREMENT/DECREMENT WHILE GRADE IS OUTRANGE" << std::endl;
	Bureaucrat	Jim("Halper", 1000);
	Bureaucrat	Pam("Pamela", 150);
	Bureaucrat	Andy("Andrew", 1);
	std::cout << Jim << Pam << Andy;
	Jim.incrGrade();
	Pam.decrGrade();
	Andy.incrGrade();
	std::cout << std::endl << std::endl;
	std::cout << "//////////////////////////////////////////// Ex01 ////////////////////////////////////////////" << std::endl << std::endl;
	std::cout << "______________________________________________________	   ______________________________________________________" << std::endl;
	std::cout << "______________________________________________________TEST 05______________________________________________________" << std::endl << std::endl;
	std::cout << "5. TEST INSTANTIATE DIFFERENTS FORMS" << std::endl;
	Form	Paperwork("Paperwork", 75, 1);
	Form	Formular("Form", 0, 1000);
	std::cout << Paperwork << Formular;
	std::cout << std::endl << std::endl;
	std::cout << "______________________________________________________       _____________________________________________________" << std::endl;
	std::cout << "______________________________________________________TEST 06_____________________________________________________" << std::endl << std::endl;
	std::cout << "6. TEST SIGN SOME FORMS" << std::endl;
	Form	Blanksheet("Blank sheet", 1000, 1000);
	Andy.signForm(Formular);
	Jim.signForm(Paperwork);
	Pam.signForm(Blanksheet);
	while (Jim.getGrade() > Paperwork.getSignable())
		Jim.incrGrade();
	Jim.signForm(Paperwork);
	Dwight.signForm(Paperwork);
	std::cout << std::endl << Paperwork << Formular << Blanksheet;
	return (0);
}

