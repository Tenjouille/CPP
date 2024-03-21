/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:42:19 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/13 15:12:36 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include "Contact.class.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
public:
	std::string ft_new_info(std::string f_name, std::string msg, std::string info);
	int			ft_digitstr(std::string str);
	int			ft_menu(std::string order);
	int			ft_exit(void);
	void		ft_new_order(int flag);
	void		ft_search(void);
	void		ft_display_infos(Contact contacts);
	void		ft_display_repertory(Contact contacts);
	void		ft_display_names(std::string name);
	void		ft_add(void);
	void		set_contact(Contact contact, int i);
	void		ft_new_contact(int i);
	Contact		get_contact(int i) const;
	PhoneBook(void);
	~PhoneBook(void);
};

#endif