/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:33:24 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/17 17:33:25 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int	main()
{
//			TEST INCREMENT AND DECREMENT FUNCTIONS
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
	std::cout << "_____________________________________________________________________________________________________________" << std::endl;
	std::cout << "_____________________________________________________________________________________________________________" << std::endl;
	//		TEST WITH OUTRANGE GRADES
	Bureaucrat	Jerry("Jerry", 0);
	Bureaucrat	John("John", -150);
	Bureaucrat	Josh ("Josh", -999999999999999999);
	Bureaucrat	Jason("Jason", 151);
	Bureaucrat	James("James", 999999999999999999);
	std::cout << Jerry << John << Josh << Jason << James;
	std::cout << "_____________________________________________________________________________________________________________" << std::endl;
	std::cout << "_____________________________________________________________________________________________________________" << std::endl;
	//		TEST WITH VALID GRADES
	Bureaucrat	Michael("Michael", 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001);
	Bureaucrat	Dwight("Dwight", +00000000000000000000000000000000000000000000000000000000000000000000002);
	Bureaucrat	Kevin("Kevin", 150);
	Bureaucrat	Oscar("Oscar", 99);
	Bureaucrat	Angela(Dwight);
	Dwight.incrGrade();
	std::cout << Michael << Dwight << Kevin << Oscar << Angela;
	std::cout << "_____________________________________________________________________________________________________________" << std::endl;
	std::cout << "_____________________________________________________________________________________________________________" << std::endl;
	//		TEST INCREMENT/DECREMENT WHILE GRADE IS OUTRANGE
	Bureaucrat	Jim("Halper", 1000);
	Bureaucrat	Pam("Pamela", 150);
	Bureaucrat	Andy("Andrew", 1);
	std::cout << Jim << Pam << Andy;
	Jim.incrGrade();
	Pam.decrGrade();
	Andy.incrGrade();
	return (0);
}

