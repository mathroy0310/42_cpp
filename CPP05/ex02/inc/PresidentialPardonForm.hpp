#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form;

class PresidentialPardonForm : public Form {
  private:
    const std::string _target;

  public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const &src);
    ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

    void execute(Bureaucrat const &executor) const;

    std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i);

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */