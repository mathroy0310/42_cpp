/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:24:21 by maroy             #+#    #+#             */
/*   Updated: 2024/03/06 00:26:21 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("default") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : Form("PresidentialPardonForm", 25, 5), _target(src.getTarget()) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = src;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm parameter constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
    (void)rhs;
    std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
    return *this;
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i) {
    o << std::boolalpha << "Form " << i.getName() << ":\n\tgrade-sign:\t" << i.getGradeToSign() << "\n\tgrade-exec:\t"
      << i.getGradeToExecute() << "\n\tis signed:\t" << i.getSigned() << std::endl;
    return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (this->getSigned() == false) {
        throw Form::FormAlreadySignedException();
    } else if (executor.getGrade() > this->getGradeToExecute()) {
        throw Form::GradeTooLowException();
    } else {
        std::cout << COLOR_BOLD << this->_target << " has been pardoned by Zafod Beeblebrox" << COLOR_RESET
                  << std::endl;
    }
}
/*
** --------------------------------- GETTERS ---------------------------------
*/

std::string PresidentialPardonForm::getTarget(void) const {
    return (this->_target);
}

/* ************************************************************************** */