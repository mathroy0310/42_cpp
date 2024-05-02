/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonAForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:24:21 by maroy             #+#    #+#             */
/*   Updated: 2024/03/06 14:21:14 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm("PresidentialPardonForm", 25, 5), _target(src.getTarget()) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = src;
}

PresidentialPardonForm::PresidentialPardonForm(std::string formName, std::string target)
    : AForm(formName, 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm parameter constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
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
	i.getSigned() ? o << COLOR_GREEN : o << COLOR_YELLOW;
    o << std::boolalpha << "Form " << i.getName() << ":\n\tgrade-sign:\t" << i.getGradeToSign() << "\n\tgrade-exec:\t"
      << i.getGradeToExecute() << "\n\tis signed:\t" << i.getSigned() << std::endl;
    o << COLOR_RESET;
	return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (this->getSigned() == false) {
        throw AForm::FormNotSignedException();
    } else if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
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
