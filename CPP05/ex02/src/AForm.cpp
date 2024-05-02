/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:12:58 by maroy             #+#    #+#             */
/*   Updated: 2024/03/06 14:20:44 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(GRADE_MIN / 2), _gradeToExecute(GRADE_MIN / 2) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < GRADE_MAX || gradeToExecute < GRADE_MAX)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > GRADE_MIN || gradeToExecute > GRADE_MIN)
        throw AForm::GradeTooLowException();

    std::cout << "AForm parameter constructor called" << std::endl;
}

AForm::AForm(const AForm &src)
    : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {
    *this = src;
    std::cout << "AForm copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &AForm::operator=(AForm const &rhs) {
    if (this != &rhs) {
        this->_signed = rhs.getSigned();
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, AForm const *a) {
	a->getSigned() ? o << COLOR_GREEN : o << COLOR_YELLOW;
    o << std::boolalpha << "AForm " << a->getName() << ":\n\tgrade-sign:\t" << a->getGradeToSign()
      << "\n\tgrade-exec:\t" << a->getGradeToExecute() << "\n\tis signed:\t" << a->getSigned() << std::endl;
	o << COLOR_RESET;
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (this->_signed)
        throw AForm::FormAlreadySignedException();
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_signed = true;
}

const std::string AForm::getName(void) const {
    return (this->_name);
}

unsigned int AForm::getGradeToSign(void) const {
    return (this->_gradeToSign);
}

unsigned int AForm::getGradeToExecute(void) const {
    return (this->_gradeToExecute);
}

bool AForm::getSigned(void) const {
    return (this->_signed);
}

/*
** -------------------------------- EXECPTIONS --------------------------------
*/

const char *AForm::GradeTooHighException::what() const throw() {
    return (COLOR_RED "CAUGHT ERROR : Grade is too High" COLOR_RESET);
}

const char *AForm::GradeTooLowException::what() const throw() {
    return (COLOR_RED "CAUGHT ERROR : Grade is too Low" COLOR_RESET);
}

const char *AForm::FormAlreadySignedException::what() const throw() {
    return (COLOR_RED "CAUGHT ERROR : AForm is already signed" COLOR_RESET);
}

const char *AForm::FormNotSignedException::what() const throw() {
    return (COLOR_RED "CAUGHT ERROR : AForm is not signed" COLOR_RESET);
}

/* ************************************************************************** */
