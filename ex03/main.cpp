/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:54:09 by ademaill          #+#    #+#             */
/*   Updated: 2025/01/31 10:54:09 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern intern;
	AForm *form;

	try
	{
		form = intern.makeForm("robotomy request", "Alice");
		delete form;
		form = intern.makeForm("shrubbery creation", "Charlie");
		delete form;
		form = intern.makeForm("presidential pardon", "David");
		delete form;
		form = intern.makeForm("random request", "Tanguy");  // Va lancer une exception
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}


