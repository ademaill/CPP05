/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:53:47 by ademaill          #+#    #+#             */
/*   Updated: 2025/01/31 10:53:47 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _execGrade;

    public:
        AForm(void);
        AForm(const AForm &copy);
        AForm(const std::string name, int signGrade, int execGrade);
        virtual ~AForm();

        AForm &operator=(const AForm &copy);

        void    beSigned(Bureaucrat &signer);
        void    execute(Bureaucrat const &executor) const;
        virtual void    beExecute(Bureaucrat const &bureaucrat) const = 0;

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

        class FormNotSignException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &o, AForm const &form);

#endif