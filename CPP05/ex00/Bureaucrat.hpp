/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:33:14 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/17 17:33:15 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <limits>
class Bureaucrat
{
private:
    std::string const   _name;
    long long           _grade;
public:

    class   GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class   GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    Bureaucrat(std::string const name, long long const grade);
    Bureaucrat();
    Bureaucrat(Bureaucrat const & src);
    Bureaucrat& operator=(Bureaucrat const & hrs);
    ~Bureaucrat();

    void        incrGrade();
    void        decrGrade();
    std::string getName() const;
    long long   getGrade() const;
};

std::ostream&   operator<<(std::ostream& o, Bureaucrat const &  targ);

#endif