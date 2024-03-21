/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:36:37 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/23 12:06:44 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm(void) : AForm("ShruberryCreationForm", 145, 137), _target("target")
{
	std::cout << "\033[42mA default SCF has been printed\033[0m" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(std::string const target) : AForm("ShruberryCreationForm", 145, 137), _target(target)
{
	std::cout << "\033[42mA new SCF has been printed, targeting "<< target << "\033[0m" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(ShruberryCreationForm const & targ) : AForm("ShruberryCreationForm", 145, 137), _target(targ._target)
{
	std::cout << "\033[42mA new SCF has been printed, from the one targeting "<< targ._target << "\033[0m" << std::endl;
}

ShruberryCreationForm::~ShruberryCreationForm()
{
	std::cout << "\033[42mSCF targeting "<< this->_target << " has been removed\033[0m" << std::endl;
}

ShruberryCreationForm&	ShruberryCreationForm::operator=(ShruberryCreationForm const & targ)
{
	this->_target = targ._target;
	return (*this);
}

void	ShruberryCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getStatus() == false)
		throw UnsignedFormException();
	if (executor.getGrade() > this->getExecutable())
		throw GradeTooLowException();
	std::ofstream	outfile((this->_target + "_shruberry").c_str());
	if (!outfile.is_open())
		throw OpenIssueException();
	outfile << "                     .o00o                                .o00o                             .o00o                                .o00o" << std::endl;
	outfile << "                   o000000oo                            o000000oo                         o000000oo                            o000000oo" << std::endl;
	outfile << "                  00000000000o                         00000000000o                      00000000000o                         00000000000o" << std::endl;
	outfile << "                 00000000000000                       00000000000000                    00000000000000                       00000000000000" << std::endl;
	outfile << "              oooooo  00000000  o88o               oooooo  00000000  o88o            oooooo  00000000  o88o               oooooo  00000000  o88o" << std::endl;
	outfile << "           ooOOOOOOOoo  ```''  888888           ooOOOOOOOoo  ```''  888888        ooOOOOOOOoo  ```''  888888           ooOOOOOOOoo  ```''  888888" << std::endl;
	outfile << "         OOOOOOOOOOOO'.qQQQQq. `8888'         OOOOOOOOOOOO'.qQQQQq. `8888'      OOOOOOOOOOOO'.qQQQQq. `8888'         OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl;
	outfile << "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'         oOOOOOOOOOO'.QQQQQQQQQQ/.88'      oOOOOOOOOOO'.QQQQQQQQQQ/.88'         oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl;
	outfile << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q           OOOOOOOOOO'.QQQQQQQQQQ/ /q        OOOOOOOOOO'.QQQQQQQQQQ/ /q           OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl;
	outfile << "         OOOOOOOOO QQQQQQQQQQ/ /QQ            OOOOOOOOO QQQQQQQQQQ/ /QQ         OOOOOOOOO QQQQQQQQQQ/ /QQ            OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl;
	outfile << "           OOOOOOOOO `QQQQQQ/ /QQ'              OOOOOOOOO `QQQQQQ/ /QQ'           OOOOOOOOO `QQQQQQ/ /QQ'              OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl;
	outfile << "             OO:F_P:O `QQQ/  /Q'                  OO:F_P:O `QQQ/  /Q'               OO:F_P:O `QQQ/  /Q'                  OO:F_P:O `QQQ/  /Q'" << std::endl;
	outfile << "                \\\\. \\ |  // |                        \\\\. \\ |  // |                     \\\\. \\ |  // |                        \\\\. \\ |  // |" << std::endl;
	outfile << "                d\\ \\\\\\|_////                         d\\ \\\\\\|_////                      d\\ \\\\\\|_////                         d\\ \\\\\\|_////" << std::endl;
	outfile << "                qP| \\\\ _' `|Ob                       qP| \\\\ _' `|Ob                    qP| \\\\ _' `|Ob                       qP| \\\\ _' `|Ob" << std::endl;
	outfile << "                   \\  / \\  \\Op                          \\  / \\  \\Op                       \\  / \\  \\Op                          \\  / \\  \\Op" << std::endl;
	outfile << "                   |  | O| |                            |  | O| |                         |  | O| |                            |  | O| |" << std::endl;
	outfile << "           _       /\\. \\_/ /\\                   _       /\\. \\_/ /\\                _       /\\. \\_/ /\\                   _       /\\. \\_/ /\\" << std::endl;
	outfile << "            `---__/|_\\\\   //|  __                `---__/|_\\\\   //|  __             `---__/|_\\\\   //|  __                `---__/|_\\\\   //|  __" << std::endl;
	outfile << "                  `-'  `-'`-'-'                        `-'  `-'`-'-'                     `-'  `-'`-'-'                        `-'  `-'`-'-'" << std::endl;
	outfile << "                     .o00o                                .o00o                             .o00o                                .o00o" << std::endl;
	outfile << "                   o000000oo                            o000000oo                         o000000oo                            o000000oo" << std::endl;
	outfile << "                  00000000000o                         00000000000o                      00000000000o                         00000000000o" << std::endl;
	outfile << "                 00000000000000                       00000000000000                    00000000000000                       00000000000000" << std::endl;
	outfile << "              oooooo  00000000  o88o               oooooo  00000000  o88o            oooooo  00000000  o88o               oooooo  00000000  o88o" << std::endl;
	outfile << "           ooOOOOOOOoo  ```''  888888           ooOOOOOOOoo  ```''  888888        ooOOOOOOOoo  ```''  888888           ooOOOOOOOoo  ```''  888888" << std::endl;
	outfile << "         OOOOOOOOOOOO'.qQQQQq. `8888'         OOOOOOOOOOOO'.qQQQQq. `8888'      OOOOOOOOOOOO'.qQQQQq. `8888'         OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl;
	outfile << "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'         oOOOOOOOOOO'.QQQQQQQQQQ/.88'      oOOOOOOOOOO'.QQQQQQQQQQ/.88'         oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl;
	outfile << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q           OOOOOOOOOO'.QQQQQQQQQQ/ /q        OOOOOOOOOO'.QQQQQQQQQQ/ /q           OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl;
	outfile << "         OOOOOOOOO QQQQQQQQQQ/ /QQ            OOOOOOOOO QQQQQQQQQQ/ /QQ         OOOOOOOOO QQQQQQQQQQ/ /QQ            OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl;
	outfile << "           OOOOOOOOO `QQQQQQ/ /QQ'              OOOOOOOOO `QQQQQQ/ /QQ'           OOOOOOOOO `QQQQQQ/ /QQ'              OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl;
	outfile << "             OO:F_P:O `QQQ/  /Q'                  OO:F_P:O `QQQ/  /Q'               OO:F_P:O `QQQ/  /Q'                  OO:F_P:O `QQQ/  /Q'" << std::endl;
	outfile << "                \\\\. \\ |  // |                        \\\\. \\ |  // |                     \\\\. \\ |  // |                        \\\\. \\ |  // |" << std::endl;
	outfile << "                d\\ \\\\\\|_////                         d\\ \\\\\\|_////                      d\\ \\\\\\|_////                         d\\ \\\\\\|_////" << std::endl;
	outfile << "                qP| \\\\ _' `|Ob                       qP| \\\\ _' `|Ob                    qP| \\\\ _' `|Ob                       qP| \\\\ _' `|Ob" << std::endl;
	outfile << "                   \\  / \\  \\Op                          \\  / \\  \\Op                       \\  / \\  \\Op                          \\  / \\  \\Op" << std::endl;
	outfile << "                   |  | O| |                            |  | O| |                         |  | O| |                            |  | O| |" << std::endl;
	outfile << "           _       /\\. \\_/ /\\                   _       /\\. \\_/ /\\                _       /\\. \\_/ /\\                   _       /\\. \\_/ /\\" << std::endl;
	outfile << "            `---__/|_\\\\   //|  __                `---__/|_\\\\   //|  __             `---__/|_\\\\   //|  __                `---__/|_\\\\   //|  __" << std::endl;
	outfile << "                  `-'  `-'`-'-'                        `-'  `-'`-'-'                     `-'  `-'`-'-'                        `-'  `-'`-'-'" << std::endl;
	outfile << "                     .o00o                                .o00o                             .o00o                                .o00o" << std::endl;
	outfile << "                   o000000oo                            o000000oo                         o000000oo                            o000000oo" << std::endl;
	outfile << "                  00000000000o                         00000000000o                      00000000000o                         00000000000o" << std::endl;
	outfile << "                 00000000000000                       00000000000000                    00000000000000                       00000000000000" << std::endl;
	outfile << "              oooooo  00000000  o88o               oooooo  00000000  o88o            oooooo  00000000  o88o               oooooo  00000000  o88o" << std::endl;
	outfile << "           ooOOOOOOOoo  ```''  888888           ooOOOOOOOoo  ```''  888888        ooOOOOOOOoo  ```''  888888           ooOOOOOOOoo  ```''  888888" << std::endl;
	outfile << "         OOOOOOOOOOOO'.qQQQQq. `8888'         OOOOOOOOOOOO'.qQQQQq. `8888'      OOOOOOOOOOOO'.qQQQQq. `8888'         OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl;
	outfile << "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'         oOOOOOOOOOO'.QQQQQQQQQQ/.88'      oOOOOOOOOOO'.QQQQQQQQQQ/.88'         oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl;
	outfile << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q           OOOOOOOOOO'.QQQQQQQQQQ/ /q        OOOOOOOOOO'.QQQQQQQQQQ/ /q           OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl;
	outfile << "         OOOOOOOOO QQQQQQQQQQ/ /QQ            OOOOOOOOO QQQQQQQQQQ/ /QQ         OOOOOOOOO QQQQQQQQQQ/ /QQ            OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl;
	outfile << "           OOOOOOOOO `QQQQQQ/ /QQ'              OOOOOOOOO `QQQQQQ/ /QQ'           OOOOOOOOO `QQQQQQ/ /QQ'              OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl;
	outfile << "             OO:F_P:O `QQQ/  /Q'                  OO:F_P:O `QQQ/  /Q'               OO:F_P:O `QQQ/  /Q'                  OO:F_P:O `QQQ/  /Q'" << std::endl;
	outfile << "                \\\\. \\ |  // |                        \\\\. \\ |  // |                     \\\\. \\ |  // |                        \\\\. \\ |  // |" << std::endl;
	outfile << "                d\\ \\\\\\|_////                         d\\ \\\\\\|_////                      d\\ \\\\\\|_////                         d\\ \\\\\\|_////" << std::endl;
	outfile << "                qP| \\\\ _' `|Ob                       qP| \\\\ _' `|Ob                    qP| \\\\ _' `|Ob                       qP| \\\\ _' `|Ob" << std::endl;
	outfile << "                   \\  / \\  \\Op                          \\  / \\  \\Op                       \\  / \\  \\Op                          \\  / \\  \\Op" << std::endl;
	outfile << "                   |  | O| |                            |  | O| |                         |  | O| |                            |  | O| |" << std::endl;
	outfile << "           _       /\\. \\_/ /\\                   _       /\\. \\_/ /\\                _       /\\. \\_/ /\\                   _       /\\. \\_/ /\\" << std::endl;
	outfile << "            `---__/|_\\\\   //|  __                `---__/|_\\\\   //|  __             `---__/|_\\\\   //|  __                `---__/|_\\\\   //|  __" << std::endl;
	outfile << "                  `-'  `-'`-'-'                        `-'  `-'`-'-'                     `-'  `-'`-'-'                        `-'  `-'`-'-'" << std::endl;
	outfile << "                     .o00o                                .o00o                             .o00o                                .o00o" << std::endl;
	outfile << "                   o000000oo                            o000000oo                         o000000oo                            o000000oo" << std::endl;
	outfile << "                  00000000000o                         00000000000o                      00000000000o                         00000000000o" << std::endl;
	outfile << "                 00000000000000                       00000000000000                    00000000000000                       00000000000000" << std::endl;
	outfile << "              oooooo  00000000  o88o               oooooo  00000000  o88o            oooooo  00000000  o88o               oooooo  00000000  o88o" << std::endl;
	outfile << "           ooOOOOOOOoo  ```''  888888           ooOOOOOOOoo  ```''  888888        ooOOOOOOOoo  ```''  888888           ooOOOOOOOoo  ```''  888888" << std::endl;
	outfile << "         OOOOOOOOOOOO'.qQQQQq. `8888'         OOOOOOOOOOOO'.qQQQQq. `8888'      OOOOOOOOOOOO'.qQQQQq. `8888'         OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl;
	outfile << "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'         oOOOOOOOOOO'.QQQQQQQQQQ/.88'      oOOOOOOOOOO'.QQQQQQQQQQ/.88'         oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl;
	outfile << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q           OOOOOOOOOO'.QQQQQQQQQQ/ /q        OOOOOOOOOO'.QQQQQQQQQQ/ /q           OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl;
	outfile << "         OOOOOOOOO QQQQQQQQQQ/ /QQ            OOOOOOOOO QQQQQQQQQQ/ /QQ         OOOOOOOOO QQQQQQQQQQ/ /QQ            OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl;
	outfile << "           OOOOOOOOO `QQQQQQ/ /QQ'              OOOOOOOOO `QQQQQQ/ /QQ'           OOOOOOOOO `QQQQQQ/ /QQ'              OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl;
	outfile << "             OO:F_P:O `QQQ/  /Q'                  OO:F_P:O `QQQ/  /Q'               OO:F_P:O `QQQ/  /Q'                  OO:F_P:O `QQQ/  /Q'" << std::endl;
	outfile << "                \\\\. \\ |  // |                        \\\\. \\ |  // |                     \\\\. \\ |  // |                        \\\\. \\ |  // |" << std::endl;
	outfile << "                d\\ \\\\\\|_////                         d\\ \\\\\\|_////                      d\\ \\\\\\|_////                         d\\ \\\\\\|_////" << std::endl;
	outfile << "                qP| \\\\ _' `|Ob                       qP| \\\\ _' `|Ob                    qP| \\\\ _' `|Ob                       qP| \\\\ _' `|Ob" << std::endl;
	outfile << "                   \\  / \\  \\Op                          \\  / \\  \\Op                       \\  / \\  \\Op                          \\  / \\  \\Op" << std::endl;
	outfile << "                   |  | O| |                            |  | O| |                         |  | O| |                            |  | O| |" << std::endl;
	outfile << "           _       /\\. \\_/ /\\                   _       /\\. \\_/ /\\                _       /\\. \\_/ /\\                   _       /\\. \\_/ /\\" << std::endl;
	outfile << "            `---__/|_\\\\   //|  __                `---__/|_\\\\   //|  __             `---__/|_\\\\   //|  __                `---__/|_\\\\   //|  __" << std::endl;
	outfile << "                  `-'  `-'`-'-'                        `-'  `-'`-'-'                     `-'  `-'`-'-'                        `-'  `-'`-'-'" << std::endl;
	outfile.close();
}