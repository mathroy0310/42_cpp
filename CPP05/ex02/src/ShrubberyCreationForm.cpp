/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:10:02 by maroy             #+#    #+#             */
/*   Updated: 2024/03/06 00:29:51 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm parameter constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : Form("ShrubberyCreationForm", 145, 137), _target(src.getTarget()) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
    (void)rhs;
    std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
    return *this;
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i) {
    o << std::boolalpha << "Form " << i.getName() << ":\n\tgrade-sign:\t" << i.getGradeToSign() << "\n\tgrade-exec:\t"
      << i.getGradeToExecute() << "\n\tis signed:\t" << i.getSigned() << std::endl;
    return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (this->getSigned() == false)
        throw Form::FormAlreadySignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    std::ofstream outfile((this->_target + "_shrubbery").c_str());
    if (outfile.is_open()) {
        outfile << "           \\/ |    |/         \n"
                   "        \\/ / \\||/  /_/___/_  \n"
                   "  _\\__\\_\\   |  /_____/_     \n"
                   "         \\  | /          /    \n"
                   " __ _-----`  |{,-----------~   \n"
                   "           \\ }{               \n"
                   "             }{{               \n"
                   "             }}{               \n"
                   "             {{}               \n"
                   "       , -=-~{ .-^- _          \n";
        outfile.close();
    }
    std::cout << COLOR_BOLD << executor.getName() << " Created a tree !" << COLOR_RESET << std::endl;
}

/*
** --------------------------------- GETTERS ---------------------------------
*/

std::string ShrubberyCreationForm::getTarget(void) const {
    return (this->_target);
}

/* ************************************************************************** */