/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:41:08 by maroy             #+#    #+#             */
/*   Updated: 2024/05/06 19:58:19 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("Default"), _grade(ECHELON_MIN / 2) {
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade < ECHELON_MAX)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > ECHELON_MIN)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
    std::cout << "Parametric constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName() + "_copy") {
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

unsigned int Bureaucrat::getGrade(void) const {
    return (this->_grade);
}

void Bureaucrat::decrementGrade(void) {
    if (this->_grade == ECHELON_MIN)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::incrementGrade(void) {
    if (this->_grade == ECHELON_MAX)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
    if (this != &rhs)
        this->_grade = rhs.getGrade();
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i) {
    o << i.getName() << ", bureaucrat grade " << i.getGrade();
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
