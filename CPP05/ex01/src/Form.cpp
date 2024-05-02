/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:12:58 by maroy             #+#    #+#             */
/*   Updated: 2024/05/02 13:31:48 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("Default"), _signed(false), _gradeToSign(GRADE_MAX / 2), _gradeToExecute(GRADE_MAX / 2) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < GRADE_MAX || gradeToExecute < GRADE_MAX)
        throw Form::GradeTooHighException();
    else if (gradeToSign > GRADE_MIN || gradeToExecute > GRADE_MIN)
        throw Form::GradeTooLowException();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &src)
    : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {
    *this = src;
    std::cout << "Form copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

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

	i.getSigned() ? o << COLOR_GREEN : o << COLOR_YELLOW;
    o << std::boolalpha << "Name = " << i.getName() << ", Grade to Sign = " << i.getGradeToSign()
      << ", Grade to Execute = " << i.getGradeToExecute() << ", Signed = " << i.getSigned() << std::endl;
	o << COLOR_RESET;
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (this->_signed)
        throw Form::FormAlreadySignedException();
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_signed = true;
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
