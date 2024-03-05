/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:13:09 by maroy             #+#    #+#             */
/*   Updated: 2024/03/05 16:13:59 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

#define ECHELON_MAX 150
#define ECHELON_MIN 1

#define COLOR_RESET "\x1b[0m"
#define COLOR_RED "\x1b[31m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_GREEN "\x1b[32m"

class Bureaucrat;

class Form {
  private:
    const std::string _name;
    bool _signed;
    const unsigned int _gradeToSign;
    const unsigned int _gradeToExecute;

  public:
    Form();
    Form(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
    Form(Form const &src);
    ~Form();

    Form &operator=(Form const &rhs);

    void signForm(Bureaucrat &bureaucrat);

    const std::string getName(void) const;
    unsigned int getGradeToSign(void) const;
    unsigned int getGradeToExecute(void) const;
    bool getSigned(void) const;

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
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif /* ************************************************************ FORM_H */
