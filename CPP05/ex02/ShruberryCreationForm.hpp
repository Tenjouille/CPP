/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:52:50 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/22 16:51:13 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShruberryCreationForm : public AForm
{
private:
	std::string	_target;
public:
	ShruberryCreationForm();
	ShruberryCreationForm(std::string const target);
	ShruberryCreationForm(ShruberryCreationForm const & targ);
	virtual ~ShruberryCreationForm();
	ShruberryCreationForm&	operator=(ShruberryCreationForm const & targ);
	
	virtual void	execute(Bureaucrat const & executor) const;
};
