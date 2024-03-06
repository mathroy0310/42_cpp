/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:13:09 by maroy             #+#    #+#             */
/*   Updated: 2024/03/06 14:20:27 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

#define GRADE_MAX 150
#define GRADE_MIN 1

#define COLOR_RESET "\x1b[0m"
#define COLOR_RED "\x1b[31m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_BOLD "\x1b[1;37m"

class Bureaucrat;

class AForm {
  protected:
    const std::string _name;
    bool _signed;
    const unsigned int _gradeToSign;
    const unsigned int _gradeToExecute;

  public:
    AForm();
    AForm(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
    AForm(AForm const &src);

    virtual ~AForm();

    AForm &operator=(AForm const &rhs);

    void beSigned(const Bureaucrat &bureaucrat);

    const std::string getName(void) const;
    unsigned int getGradeToSign(void) const;
    unsigned int getGradeToExecute(void) const;
    bool getSigned(void) const;

    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class FormAlreadySignedException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, AForm const *a);

#endif /* ************************************************************ AFORM_H */
