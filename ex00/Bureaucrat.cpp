/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:11:09 by ademaill          #+#    #+#             */
/*   Updated: 2025/01/28 11:22:17 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called : " << this->_name << " with grade of " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat constructor called : "	<< this->_name << " with grade of " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.GetName() + "_copy")
{
	std::cout << "Bureaucrat copy constructor called to copy " << src.GetName() << " into " << this->_name << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called for : " << this->_name << std::endl; 
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		_grade = src._grade;
	return *this;
}

std::string	Bureaucrat::GetName() const
{
	return this->_name;
}

unsigned int	Bureaucrat::GetGrade()
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade += 1;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade too high !";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low !";
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << a->GetName() << " Bureaucrat of grade "
	<< a->GetGrade();
	return o;
}