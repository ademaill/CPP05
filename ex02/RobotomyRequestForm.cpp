#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm::AForm("RobotomyRequestForm", 72, 45), _target("null")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm::AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm const &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    AForm::operator=(copy);
    this->_target = copy._target;
    return *this;
}

void    RobotomyRequestForm::beExecute(const Bureaucrat &bureaucrat) const
{
    (void)bureaucrat;
    
    int success;

    srand((unsigned) time(NULL));
    success = rand() % 2;
    if (success)
        std::cout << this->_target << " has been robotomized succesfully" << std::endl;
    else
        std::cout << this->_target << "'s robotomization failed" << std::endl;
}

std::ostream &operator<<(std::ostream &str, RobotomyRequestForm const &form)
{
    return (std::cout << form.getName() << " form, signed : " << form.getIsSigned() << ", sign grade : " << form.getSignGrade() << ", exec grade : " << form.getExecGrade() << std::endl);
}