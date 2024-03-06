#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"


class AForm;

class Intern {

  public:
    Intern();
    Intern(Intern const &src);
    ~Intern();

    Intern &operator=(Intern const &rhs);

    AForm *makeForm(std::string formName, std::string target);

    AForm *(Intern::*formCreators[3])(std::string, std::string);

	class UnknownFormException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

  private:
    AForm *createShrubberyCreationForm(std::string formName, std::string target);
    AForm *createRobotomyRequestForm(std::string formName, std::string target);
    AForm *createPresidentialPardonForm(std::string formName, std::string target);
};

#endif /* ********************************************************** INTERN_H */
