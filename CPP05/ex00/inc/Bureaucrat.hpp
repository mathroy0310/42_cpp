/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:41:10 by maroy             #+#    #+#             */
/*   Updated: 2024/05/02 13:04:39 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include <exception>

#define ECHELON_MAX 1
#define ECHELON_MIN 150

#define COLOR_RESET "\x1b[0m"
#define COLOR_RED "\x1b[31m"
#define COLOR_CYAN "\x1b[36m"

class Bureaucrat {
  private:
    const std::string _name;
    unsigned int _grade;

  public:
    Bureaucrat();
    Bureaucrat(Bureaucrat const &src);
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();

    Bureaucrat &operator=(Bureaucrat const &rhs);
    std::string getName(void) const;
    unsigned int getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);

    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif /* ******************************************** BUREAUCRAT_H */
