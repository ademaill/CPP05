#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
    this->_grade = grade;
    if (this->_grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if (this->_grade > 150)
        throw(Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
    *this = copy;
}

Bureaucrat::~Bureaucrat(void)
{

}

Bureaucrat const    &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this == &copy)
        return *this;
    this->_grade = copy._grade;
    return *this;
}

const std::string  &Bureaucrat::getName(void) const
{
    return this->_name;
}

int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

void    Bureaucrat::Gradeup(void)
{
    this->_grade--;
    if (this->_grade < 1)
        throw(Bureaucrat::GradeTooHighException());
}

void    Bureaucrat::GradeDown(void)
{
    this->_grade++;
    if (this->_grade > 150)
        throw(Bureaucrat::GradeTooLowException());
}

void    Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signs " << form.getName() << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << this->_name << " cannot sign " << form.getName() << " because : " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " cannot execute " << form.getName() << " because : " << e.what() << std::endl;
    }
}

char const  *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "Grade is too high";
}

char const  *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "Grade is to low";
}

std::ostream    &operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
    return (str << bureaucrat.getName() << " , bureaucrat grade " << bureaucrat.getGrade());
}