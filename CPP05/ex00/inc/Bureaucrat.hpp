/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:41:10 by maroy             #+#    #+#             */
/*   Updated: 2024/03/05 14:58:24 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include <exception>

#define ECHELON_MAX 150
#define ECHELON_MIN 1

#define COLOR_RESET "\x1b[0m"
#define COLOR_RED "\x1b[31m"
#define COLOR_CYAN "\x1b[36m"

class Bureaucrat {
  private:
    const std::string _name;
    unsigned int _echelon;

  public:
    Bureaucrat();
    Bureaucrat(Bureaucrat const &src);
    Bureaucrat(std::string name, unsigned int echelon);
    ~Bureaucrat();

    Bureaucrat &operator=(Bureaucrat const &rhs);
    std::string getName(void) const;
    unsigned int getEchelon(void) const;
    void incrementEchelon(void);
    void decrementEchelon(void);

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
