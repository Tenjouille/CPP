/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:32:57 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/22 18:35:02 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const & targ);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm&	operator=(PresidentialPardonForm const & targ);
	
	virtual void	execute(Bureaucrat const & executor) const;
};
