/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:35:35 by maroy             #+#    #+#             */
/*   Updated: 2024/03/06 15:16:20 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern() {
    std::cout << "Default constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
    (void)src;
    std::cout << "Copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() {
    std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &Intern::operator=(Intern const &rhs) {
    (void)rhs;
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}

/*
** --------------------------------- PRIVATE ----------------------------------
*/

AForm *Intern::createShrubberyCreationForm(std::string formName, std::string target) {
    return new ShrubberyCreationForm(formName, target);
}

AForm *Intern::createRobotomyRequestForm(std::string formName, std::string target) {
    return new RobotomyRequestForm(formName, target);
}

AForm *Intern::createPresidentialPardonForm(std::string formName, std::string target) {
    return new PresidentialPardonForm(formName, target);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm *Intern::makeForm(std::string formName, std::string target) {
    formCreators[0] = &Intern::createShrubberyCreationForm;
    formCreators[1] = &Intern::createRobotomyRequestForm;
    formCreators[2] = &Intern::createPresidentialPardonForm;

    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(formName, target);
        }
    }
    throw Intern::UnknownFormException();
}

/* ************************************************************************** */

const char *Intern::UnknownFormException::what() const throw() {
    return (COLOR_RED "CAUGHT ERROR : Form Request not found" COLOR_RESET);
}
