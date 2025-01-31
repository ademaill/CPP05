/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:56:27 by ademaill          #+#    #+#             */
/*   Updated: 2025/01/31 10:56:27 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _execGrade;

    public:
        Form(void);
        Form(const Form &copy);
        Form(const std::string name, int signGrade, int execGrade);
        ~Form();

        Form &operator=(const Form &copy);

        void    beSigned(Bureaucrat &signer);

        std::string const   &getName(void)const;
        bool                getIsSigned(void)const;
        int                 getSignGrade(void)const;
        int                 getExecGrade(void)const;

        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &o, Form const &form);

#endif