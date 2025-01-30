#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("default"), _isSigned(0), _signGrade(30), _execGrade(60)
{

}

AForm::AForm(const std::string name, int signGrade, int execGrade) : _name(name), _isSigned(0), _signGrade(signGrade), _execGrade(execGrade)
{
    if (this->_signGrade < 1)
        throw(AForm::GradeTooHighException());
    else if (this->_signGrade > 150)
        throw(AForm::GradeTooLowException());
    if (this->_execGrade < 1)
        throw(AForm::GradeTooHighException());
    else if (this->_execGrade > 150)
        throw(AForm::GradeTooLowException());
}

AForm::AForm(AForm const &copy) : _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
    *this = copy;
}

AForm::~AForm(void)
{

}

AForm  &AForm::operator=(const AForm &copy)
{
    this->_isSigned = copy._isSigned;
    return *this;
}

std::string const   &AForm::getName(void)const
{
    return this->_name;
}

int AForm::getSignGrade(void)const
{
    return this->_signGrade;
}

int AForm::getExecGrade(void)const
{
    return this->_execGrade;
}

bool  AForm::getIsSigned(void)const
{
    return this->_isSigned;
}

void    AForm::beSigned(Bureaucrat &signer)
{
    if (signer.getGrade() > this->_signGrade)
        throw(AForm::GradeTooLowException());
    else
    {
        this->_isSigned = 1;
        std::cout << signer.getName() << " successfully signed " << this->_name << std::endl;
    }
}

void    AForm::execute(Bureaucrat const &executor) const
{
    if (!this->_isSigned)
        throw(AForm::FormNotSignException());
    else if (executor.getGrade() > this->_signGrade)
        throw(AForm::GradeTooLowException());
    else
    {
        std::cout << executor.getName() << " executes form: " << this->_name << std::endl;
        this->beExecute(executor);
    }
}

char const  *AForm::GradeTooHighException::what(void) const throw()
{
    return "Grade is too high";
}

char const  *AForm::GradeTooLowException::what(void) const throw()
{
    return "Grade is too low";
}

char const *AForm::FormNotSignException::what(void) const throw()
{
    return "From not signed";
}
std::ostream    &operator<<(std::ostream &str, AForm const &form)
{
    return (str << form.getName() << " form, signed : " << form.getIsSigned() << ", sign grade : " << form.getSignGrade() << ", exec grade : " << form.getExecGrade());
}