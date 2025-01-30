#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
    private:
        std::string _target;

    public:

        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        ~RobotomyRequestForm(void);

        void    beExecute(Bureaucrat const &bureaucrat) const;

        RobotomyRequestForm const &operator=(RobotomyRequestForm const &copy);

};

std::ostream &operator<<(std::ostream &str, RobotomyRequestForm const &form);

#endif