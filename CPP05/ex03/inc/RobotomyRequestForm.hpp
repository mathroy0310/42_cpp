/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:25:24 by maroy             #+#    #+#             */
/*   Updated: 2024/03/06 14:42:46 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm {
  private:
    const std::string _target;

  public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
	RobotomyRequestForm(std::string formName, std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &src);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

    void execute(Bureaucrat const &executor) const;
    std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i);

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */
