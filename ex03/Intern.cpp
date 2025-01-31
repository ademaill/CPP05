/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:23:43 by ademaill          #+#    #+#             */
/*   Updated: 2025/01/31 15:46:46 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{	
}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern::~Intern(void)
{
}

Intern	&Intern::operator=(Intern const &copy)
{
	(void) copy;
	return *this;
}

AForm *Intern::makeForm(std::string const &type, std::string const &target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *forms[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	// Shearch form
	for (int i = 0; i < 3; i++)
	{
		if (type == formNames[i])
		{
			std::cout << "Intern creates " << formNames[i] << std::endl;
			return forms[i];
		}
	}

	throw AForm::FormInvalidException();
}

