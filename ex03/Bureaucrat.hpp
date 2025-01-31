/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:54:02 by ademaill          #+#    #+#             */
/*   Updated: 2025/01/31 10:54:02 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class   Bureaucrat
{
    private :
        const std::string   _name;
        size_t              _grade;


    public :
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        ~Bureaucrat();

        Bureaucrat const    &operator=(Bureaucrat const &copy);

        const std::string   &getName(void) const;
        int                 getGrade(void) const;

        void    Gradeup(void);
        void    GradeDown(void);
        void    signForm(AForm &form);
        void    executeForm(AForm const &form);

        class   GradeTooHighException : public std::exception
        {
            public :
                virtual char const  *what(void) const throw();
        };

        class   GradeTooLowException : public std::exception
        {
            public :
                virtual char const *what(void) const throw();
        };
};

std::ostream    &operator<<(std::ostream &str, Bureaucrat const &bureaucrat);

#endif