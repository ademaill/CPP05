/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:39:24 by ademaill          #+#    #+#             */
/*   Updated: 2025/01/28 11:21:13 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

class	Bureaucrat
{
	private :

		const std::string _name;
		unsigned int _grade;

	public :

		Bureaucrat();
		Bureaucrat(std::string _name, unsigned int grade);
		Bureaucrat(const Bureaucrat &copy);

		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &src);

		std::string		GetName() const;
		unsigned int	GetGrade();

		void	incrementGrade();
		void	decrementGrade();

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw(); 
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();	
		};

};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif