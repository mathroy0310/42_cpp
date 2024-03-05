/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:41:08 by maroy             #+#    #+#             */
/*   Updated: 2024/03/05 16:11:05 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("Default"), _echelon(ECHELON_MAX / 2) {
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int echelon) : _name(name) {
    if (echelon < ECHELON_MIN)
        throw Bureaucrat::GradeTooHighException();
    else if (echelon > ECHELON_MAX)
        throw Bureaucrat::GradeTooLowException();
    this->_echelon = echelon;
    std::cout << "Parametric constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
    *this = src;
    std::cout << "Copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" << std::endl;
}

/*
** -------------------------------- METHODES -----------------------------------
*/

std::string Bureaucrat::getName(void) const {
    return (this->_name);
}

unsigned int Bureaucrat::getEchelon(void) const {
    return (this->_echelon);
}

void Bureaucrat::decrementEchelon(void) {
    if (this->_echelon == ECHELON_MAX)
        throw Bureaucrat::GradeTooHighException();
    this->_echelon++;
}

void Bureaucrat::incrementEchelon(void) {
    if (this->_echelon == ECHELON_MIN)
        throw Bureaucrat::GradeTooLowException();
    this->_echelon--;
}

void Bureaucrat::beSigned(Form &form) {
    try {
        form.signForm(*this);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
    if (this != &rhs)
        this->_echelon = rhs.getEchelon();
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i) {
    o << i.getName() << ", bureaucrat grade " << i.getEchelon();
    return (o);
}

/*
** -------------------------------- EXECPTIONS --------------------------------
*/

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return (COLOR_RED "CAUGHT ERROR : Grade is too High" COLOR_RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return (COLOR_RED "CAUGHT ERROR : Grade is too Low" COLOR_RESET);
}

/* ************************************************************************** */
