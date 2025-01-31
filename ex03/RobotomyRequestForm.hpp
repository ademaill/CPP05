/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:54:36 by ademaill          #+#    #+#             */
/*   Updated: 2025/01/31 10:54:36 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

        std::string const &getTarget(void) const;
        
};

std::ostream &operator<<(std::ostream &str, RobotomyRequestForm const &form);

#endif