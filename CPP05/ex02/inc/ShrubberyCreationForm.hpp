#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

class Bureaucrat;
class Form;

class ShrubberyCreationForm : public Form {

  private:
    const std::string _target;

  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

    void execute(Bureaucrat const &executor) const;
    std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i);

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */