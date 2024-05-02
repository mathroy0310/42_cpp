/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:58:30 by maroy             #+#    #+#             */
/*   Updated: 2024/05/02 12:58:31 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm {

  private:
    const std::string _target;

  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(std::string formName, std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

    void execute(Bureaucrat const &executor) const;
    std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i);

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */
