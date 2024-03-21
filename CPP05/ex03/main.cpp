/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:33:34 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/29 15:19:16 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout << "//////////////////////////////////////////// Ex00 ////////////////////////////////////////////" << std::endl << std::endl;
	std::cout << "______________________________________________________	   ______________________________________________________" << std::endl;
	std::cout << "______________________________________________________TEST 01______________________________________________________" << std::endl << std::endl;
	std::cout << "1. TEST INCREMENT AND DECREMENT FUNCTIONS" << std::endl;
	Bureaucrat	bureaucrat("Jerry", 72);
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
	Bureaucrat	Dwight("Dwight", 12);
	Bureaucrat	Kevin("Kevin", 140);
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
	std::cout << "//////////////////////////////////////////// Ex01 & Ex02 && Ex03////////////////////////////////////////////" << std::endl << std::endl;
	std::cout << "______________________________________________________	   ______________________________________________________" << std::endl;
	std::cout << "______________________________________________________TEST 05______________________________________________________" << std::endl << std::endl;
	std::cout << "5. TEST INSTANTIATE DIFFERENTS FORMS" << std::endl;
	PresidentialPardonForm	Paperwork("Trump");
	RobotomyRequestForm		Formular("007");
	ShruberryCreationForm	Blanksheet("File");
	std::cout << Paperwork << Formular << Blanksheet;
	std::cout << std::endl << std::endl;
	std::cout << "______________________________________________________       _____________________________________________________" << std::endl;
	std::cout << "______________________________________________________TEST 06_____________________________________________________" << std::endl << std::endl;
	std::cout << "6. TEST SIGN SOME FORMS (feat Intern class)" << std::endl;
	Intern	Ryan;
	AForm	*ShrubForm = 0;
	AForm	*RoboForm = 0;
	AForm	*PrezForm = 0;
	AForm	*InvalidForm = 0;
	try
	{
		ShrubForm = Ryan.makeForm("ShruberryCreationForm", "File");
		RoboForm = Ryan.makeForm("RobotomyRequestForm", "007");
		PrezForm = Ryan.makeForm("PresidentialPardonForm", "Trump");
		InvalidForm = Ryan.makeForm("Invalid form", "Boss");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	if (!InvalidForm)
		std::cout << "Invalid form = 0" << std::endl;
	std::cout << "[ShruberryCreationForm]" << std::endl;
	Michael.executeForm(*ShrubForm); // Fail
	Jim.signForm(*ShrubForm); // Fail
	Kevin.signForm(*ShrubForm); // Success
	Kevin.executeForm(*ShrubForm); // Fail
	Oscar.signForm(*ShrubForm); // Fail
	Oscar.executeForm(*ShrubForm); //Success
	std::cout << std::endl << std::endl;
	std::cout << "[RobotomyRequestForm]" << std::endl;
	Michael.executeForm(*RoboForm); // Fail
	Jim.signForm(*RoboForm); // Fail
	bureaucrat.signForm(*RoboForm); // Success 
	bureaucrat.executeForm(*RoboForm); // Fail
	Michael.signForm(*RoboForm); // Fail
	Michael.executeForm(*RoboForm); //Success (50% chance to fail)
	std::cout << std::endl << std::endl;
	std::cout << "[PresidentialPardonForm]" << std::endl;
	Michael.executeForm(*PrezForm); // Fail
	Jim.signForm(*PrezForm); // Fail
	Dwight.signForm(*PrezForm); // Success
	Dwight.executeForm(*PrezForm); // Fail
	Michael.signForm(*PrezForm); // Fail
	Michael.executeForm(*PrezForm); //Success
	std::cout << std::endl << std::endl;
	delete ShrubForm;
	delete RoboForm;
	delete PrezForm;
	return (0);
}

