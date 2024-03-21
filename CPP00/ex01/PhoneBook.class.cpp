/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:17:08 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/19 23:22:38 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int	PhoneBook::ft_digitstr(std::string str)
{
	int	i = str.length();

	while (--i > 0)
	{
		if (!isdigit(str[i]))
			return (1);
	}
	return (0);	
}

std::string PhoneBook::ft_new_info(std::string f_name, std::string msg, std::string info)
{
	std::string	res;

	do
	{
		std::cout << "Please enter " << f_name << msg << std::endl;
		std::getline(std::cin, info);
		if (std::cin.eof())
			return ("");
	} while (info == "");
	for(int i = info.length() - 1; isspace(info[i]); i--)
		info.erase(i, 1);
	return (info);
}

void	PhoneBook::ft_new_contact(int i)
{
	std::string	enter = "";

	this->contacts[i].set_f_name(this->ft_new_info("your new contact", "'s first name :", this->contacts[i].get_f_name()));
	if (this->contacts[i].get_f_name() == "")
		return ;
	this->contacts[i].set_l_name(this->ft_new_info(this->contacts[i].get_f_name(), "'s last name :", this->contacts[i].get_l_name()));
	if (this->contacts[i].get_l_name() == "")
		return ;
	this->contacts[i].set_n_name(this->ft_new_info(this->contacts[i].get_f_name(), "'s nickname :", this->contacts[i].get_n_name()));
	if (this->contacts[i].get_n_name() == "")
		return ;
	this->contacts[i].set_phone_num(this->ft_new_info(this->contacts[i].get_f_name(), "'s phone number :", this->contacts[i].get_phone_num()));
	if (this->contacts[i].get_phone_num() == "")
		return ;
	while (this->ft_digitstr(this->contacts[i].get_phone_num()))
	{
		this->contacts[i].set_phone_num(this->ft_new_info(this->contacts[i].get_f_name(), "'s REAL phone number :", this->contacts[i].get_phone_num()));
		if (this->contacts[i].get_phone_num() == "")
			return ;
	}
	this->contacts[i].set_secret(this->ft_new_info(this->contacts[i].get_f_name(), "'s darkest secret :", this->contacts[i].get_secret()));
	if (this->contacts[i].get_secret() == "")
		return ;
	std::cout << "Congratulations !! Your contact " << this->contacts[i].get_f_name() << " has been added to YELLOW PAGES™" << std::endl;
	std::cout << "Tap ENTER to go back to the menu" << std::endl;
	do
	{
		std::getline(std::cin, enter);
		if (std::cin.eof())
			return ;
	} while (enter.length());
	ft_new_order(1);
}

void	PhoneBook::ft_add(void)
{
	int	i = 0;

	std::cout << "\e[1;1H\e[2J" << std::endl;
	while (i < 8 && this->get_contact(i).get_phone_num() != "")
		i++;
	if (i == 8)
		i = 0;
	this->ft_new_contact(i);
	return ;
}

void	PhoneBook::ft_display_names(std::string name)
{
	int	space = name.length();
	if (space > 10)
	{
		for(int i = 0; i < 9; i++)
			std::cout << name[i];
		std::cout << ".";
	}
	else
	{
		space = 10 - space;
		while (space > 0)
		{
			std::cout << " ";
			space--;
		}
		for (int i = 0; name[i]; i++)
			std::cout << name[i];
	}
	std::cout << "|";
}

void	PhoneBook::ft_display_repertory(Contact contacts)
{
	std::cout << "|         " << contacts.get_id() << "|";
	this->ft_display_names(contacts.get_f_name());
	this->ft_display_names(contacts.get_l_name());
	this->ft_display_names(contacts.get_n_name());
	std::cout << std::endl;
}

void	PhoneBook::ft_display_infos(Contact contacts)
{
	std::cout << "First name     : " << contacts.get_f_name() << std::endl;
	std::cout << "Last name      : " << contacts.get_l_name() << std::endl;
	std::cout << "Nickname       : " << contacts.get_n_name() << std::endl;
	std::cout << "Phone number   : " << contacts.get_phone_num() << std::endl;
	std::cout << "Darkest secret : " << contacts.get_secret() << std::endl;
	std::cout << "You can tap another contact index or you can tap ENTER to get back to menu" << std::endl;
}

void	PhoneBook::ft_search(void)
{
	std::string	enter = "";
	int			i = 0;
	
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	while(i < 8 && this->get_contact(i).get_f_name() != "")
		this->ft_display_repertory(this->get_contact(i++));
	if (i == 0)
		std::cout << "\e[1;1H\e[2JSorry you have no friends, go outside, travel, just get out of your room !" << std::endl;
	else
	{
		std::cout << "|__________|__________|__________|__________|" << std::endl;
		std::cout << "Tap a contact index to get more informations about it" << std::endl;
	}
	std::cout << "Tap ENTER to go back to the menu" << std::endl;
	do
	{
		std::getline(std::cin, enter);
		if (std::cin.eof())
			return ;
		if (enter.length() == 1 && enter[0] >= '1' && enter[0] <= i + '0')
			this->ft_display_infos(this->get_contact((int)enter[0] - '0' - 1));
	} while (enter.length());
	this->ft_new_order(1);
}

int	PhoneBook::ft_exit(void)
{
	std::string	f_order;
	std::string	r_order;

	std::cout << "Are you sure you want to EXIT  ?" << std::endl;
	std::cout << "All your contacts will be erased" << std::endl;
	std::cout << "yes\tno" << std::endl;
	do
	{
		f_order = "";
		r_order = "";
		std::getline(std::cin, f_order);
		if (std::cin.eof())
			return (1);
		for (int i = 0; f_order[i]; i++)
			if (!isspace(f_order[i]))
				r_order.push_back(f_order[i]);
		for(int i = 0; r_order[i]; i++)
			r_order[i] = toupper(r_order[i]);
		if (r_order == "YES")
			return (1);
		if (r_order == "NO")
			this->ft_new_order(1);
	} while (r_order != "NO" && r_order != "YES");
	return (1);
}

int	PhoneBook::ft_menu(std::string order)
{
	std::string	f_order = "";

	for(int i = 0; order[i]; i++)
		order[i] = toupper(order[i]);
	if (order == "ADD")
	{
		std::cout << "\e[1;1H\e[2J" << std::endl;
		ft_add();
	}
	else if (order == "SEARCH")
	{
		std::cout << "\e[1;1H\e[2J" << std::endl;
		ft_search();
	}
	else if (order == "EXIT")
	{
		std::cout << "\e[1;1H\e[2J" << std::endl;
		if (this->ft_exit())
			return (1);
	}
	else
		this->ft_new_order(2);
	return (1);
}

void	PhoneBook::ft_new_order(int flag)
{
	std::string	f_order = "";
	std::string	r_order = "";

	if (flag == 1)
		std::cout << "\e[1;1H\e[2J" << std::endl;
	if (flag != 2)
	{
		std::cout << "Please, enter one of those three valids entries :" << std::endl;
		std::cout << "ADD\tSEARCH\tEXIT" << std::endl;
	}
	std::getline(std::cin, f_order);
	if (std::cin.eof())
		return ;
	for (int i = 0; f_order[i]; i++)
		if (!isspace(f_order[i]))
			r_order.push_back(f_order[i]);
	while (!this->ft_menu(r_order))
		continue;
}

void	PhoneBook::set_contact(Contact contact, int i)
{
	contact.set_id(i);
	contact.set_f_name("");
	contact.set_l_name("");
	contact.set_n_name("");
	contact.set_phone_num("");
	contact.set_secret("");
}

Contact	PhoneBook::get_contact(int i) const
{
	return (this->contacts[i]);
}

PhoneBook::PhoneBook(void)
{
	for(int i = 1; i <= 8; i++)
	{
		this->contacts[i - 1].set_id(i);
		this->contacts[i - 1].set_f_name("");
		this->contacts[i - 1].set_l_name("");
		this->contacts[i - 1].set_n_name("");
		this->contacts[i - 1].set_phone_num("");
		this->contacts[i - 1].set_secret("");
	}
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}
