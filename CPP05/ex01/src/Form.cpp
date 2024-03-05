/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:12:58 by maroy             #+#    #+#             */
/*   Updated: 2024/03/05 16:11:19 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("Default"), _signed(false), _gradeToSign(ECHELON_MAX / 2), _gradeToExecute(ECHELON_MAX / 2) {}

Form::Form(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < ECHELON_MIN || gradeToExecute < ECHELON_MIN)
        throw Form::GradeTooHighException();
    else if (gradeToSign > ECHELON_MAX || gradeToExecute > ECHELON_MAX)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &src)
    : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &rhs) {
    if (this != &rhs) {
        this->_signed = rhs.getSigned();
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &i) {
    o << "Name = " << i.getName() << ", Grade to Sign = " << i.getGradeToSign()
      << ", Grade to Execute = " << i.getGradeToExecute() << ", Signed = " << i.getSigned() << std::endl;
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::signForm(Bureaucrat &bureaucrat) {
    if (this->getSigned() == false) {
        if (bureaucrat.getEchelon() > this->getGradeToSign())
            throw Form::GradeTooLowException();
        this->_signed = true;
        std::cout << COLOR_GREEN << bureaucrat.getName() << " signs " << this->getName() << COLOR_RESET << std::endl;
    } else
        throw Form::FormAlreadySignedException();
}

const std::string Form::getName(void) const {
    return (this->_name);
}

unsigned int Form::getGradeToSign(void) const {
    return (this->_gradeToSign);
}

unsigned int Form::getGradeToExecute(void) const {
    return (this->_gradeToExecute);
}

bool Form::getSigned(void) const {
    return (this->_signed);
}

/*
** -------------------------------- EXECPTIONS --------------------------------
*/

const char *Form::GradeTooHighException::what() const throw() {
    return (COLOR_RED "CAUGHT ERROR : Grade is too High" COLOR_RESET);
}

const char *Form::GradeTooLowException::what() const throw() {
    return (COLOR_RED "CAUGHT ERROR : Grade is too Low" COLOR_RESET);
}

const char *Form::FormAlreadySignedException::what() const throw() {
    return (COLOR_RED "CAUGHT ERROR : Form is already signed" COLOR_RESET);
}

/* ************************************************************************** */
