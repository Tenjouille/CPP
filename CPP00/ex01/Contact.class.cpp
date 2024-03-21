/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:00:00 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/13 16:23:06 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::set_id(int arg)
{
	this->id = arg;
}

int		Contact::get_id(void) const
{
	return(this->id);
}

void	Contact::set_f_name(std::string arg)
{
	this->f_name = arg;
}

std::string	Contact::get_f_name(void) const
{
	return(this->f_name);
}

void	Contact::set_l_name(std::string arg)
{
	this->l_name = arg;
}

std::string	Contact::get_l_name(void) const
{
	return(this->l_name);
}

void	Contact::set_n_name(std::string arg)
{
	this->n_name = arg;
}

std::string	Contact::get_n_name(void) const
{
	return(this->n_name);
}

void	Contact::set_phone_num(std::string arg)
{
	this->phone_num = arg;
}

std::string	Contact::get_phone_num(void) const
{
	return(this->phone_num);
}

void	Contact::set_secret(std::string arg)
{
	this->secret = arg;
}

std::string	Contact::get_secret(void) const
{
	return(this->secret);
}
