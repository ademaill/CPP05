/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:23:46 by ademaill          #+#    #+#             */
/*   Updated: 2025/01/31 15:37:39 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private :

	public :
		Intern(void);
		Intern(Intern  const &copy);
		~Intern(void);
	
		Intern &operator=(Intern const &copy);

		AForm	*makeForm(std::string const &type, std::string const &target);
		
};


#endif