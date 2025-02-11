/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:54:16 by ademaill          #+#    #+#             */
/*   Updated: 2025/01/31 10:54:16 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentialPardonForm", 25, 5), _target("null")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm::AForm(copy), _target(copy._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm const &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    AForm::operator=(copy);
    this->_target = copy._target;
    return *this;
}

void    PresidentialPardonForm::beExecute(const Bureaucrat &bureaucrat) const
{
    (void)bureaucrat;
    std::cout << this->_target << " has been pardoned by Zadof Beeblerox" << std::endl;
}

std::string const &PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

std::ostream &operator<<(std::ostream &str, PresidentialPardonForm const &form)
{
    return (str << form.getName() << " form, signed : " << form.getIsSigned() << ", sign grade : " << form.getSignGrade() << ", exec grade : " << form.getExecGrade() << std::endl);
}