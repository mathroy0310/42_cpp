/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestAForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:24:50 by maroy             #+#    #+#             */
/*   Updated: 2024/03/06 14:21:09 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm parameter constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string formName, std::string target)
	: AForm(formName, 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm parameter constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm("RobotomyRequestForm", 72, 45), _target(src.getTarget()) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
    (void)rhs;
    std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
    return *this;
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i) {
    o << std::boolalpha << "Form " << i.getName() << ":\n\tgrade-sign:\t" << i.getGradeToSign() << "\n\tgrade-exec:\t"
      << i.getGradeToExecute() << "\n\tis signed:\t" << i.getSigned() << std::endl;
    return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

static int robot_failure = 0;

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (this->getSigned() == false)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else if (robot_failure++ % 2 == 0)
        std::cout << COLOR_BOLD << "BRRRRRRRRRRRRRR " << this->getTarget() << " has been robotomized successfully"
                  << COLOR_RESET << std::endl;
    else
        std::cout << COLOR_BOLD << "Robotomization failed" << COLOR_RESET << std::endl;
}

/*
** --------------------------------- GETTERS ---------------------------------
*/

std::string RobotomyRequestForm::getTarget(void) const {
    return (this->_target);
}

/* ************************************************************************** */
