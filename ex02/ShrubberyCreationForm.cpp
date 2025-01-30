#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm::AForm("ShrubberyCreationForm", 145, 137), _target("null")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm::AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm const &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    AForm::operator=(copy);
    this->_target = copy._target;
    return *this;
}

void    ShrubberyCreationForm::beExecute(const Bureaucrat &bureaucrat) const
{
    std::ofstream outfile;

    outfile.open((this->_target + "_shrubbery").c_str());
    if (outfile.fail())
    {
        std::cout << "Could not open output file" << std::endl;
        return ;
    }
    outfile << TREE;
    outfile.close();
    std::cout << bureaucrat.getName() << " succcessfully created a shrubbery" << std::endl;
}

std::ostream &operator<<(std::ostream &str, ShrubberyCreationForm const &form)
{
    return (str << form.getName() << " form, signed : " << form.getIsSigned() << ", sign grade : " << form.getSignGrade() << ", exec grade : " << form.getExecGrade() << std::endl);
}