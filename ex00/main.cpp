/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:19:48 by ademaill          #+#    #+#             */
/*   Updated: 2025/01/28 11:59:28 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	try 
	{
		Bureaucrat *a = new Bureaucrat("bdany", 151);
		std::cout << a;
	}
	catch(std::exception &e)
	{
		std::cerr << "Error construction failed : " << e.what() << std::endl; 
	}
	try
	{
		Bureaucrat *b = new Bureaucrat("bdany", 0);
		std::cout << b;
	}
	catch(std::exception &e)
	{
		std::cerr << "Error construction failed : " << e.what() << std::endl;
	}
	
	Bureaucrat *a = new Bureaucrat("lolo", 1);
	Bureaucrat *b = new Bureaucrat(*a);
	std::cout << b << std::endl;
	try
	{
		b->decrementGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << "Error decrementation failed : " << e.what() << std::endl;
	}
	std::cout << b << std::endl;
	try 
	{
		b->incrementGrade();
		b->incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << "Error incrementation failed : " << e.what() << std::endl;
	}
	try
	{
		for (int i = 0; i < 150; i++)
			a->decrementGrade();
	}
	catch(std::exception& e)
	{
		std::cerr << "Error incrementation failed : " << e.what() << std::endl;
	}
	
	delete a;
	delete b;
	return 0;
}