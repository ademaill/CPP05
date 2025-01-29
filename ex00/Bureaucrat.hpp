#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

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
        void    signForm(Form &form);

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