#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class  Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private :
        std::string _target;
    
    public :

        PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        ~PresidentialPardonForm();

        void    beExecute(Bureaucrat const &bureaucrat) const;

        PresidentialPardonForm const    &operator=(PresidentialPardonForm const &copy);
};

std::ostream    &operator<<(std::ostream &str, PresidentialPardonForm const &form);

#endif