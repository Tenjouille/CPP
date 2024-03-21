/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:32:13 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/13 14:26:48 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>

class Contact
{
private:
	std::string f_name;
	std::string l_name;
	std::string n_name;
	std::string phone_num;
	std::string secret;
	int			id;
	
public:
	void		set_id(int arg);
	void		set_f_name(std::string arg);
	void		set_l_name(std::string arg);
	void		set_n_name(std::string arg);
	void		set_phone_num(std::string arg);
	void		set_secret(std::string arg);
	int			get_id(void) const;
	std::string	get_f_name(void) const;
	std::string	get_l_name(void) const;
	std::string	get_n_name(void) const;
	std::string	get_phone_num(void) const;
	std::string	get_secret(void) const;
	Contact(void);
	~Contact(void);
};

#endif