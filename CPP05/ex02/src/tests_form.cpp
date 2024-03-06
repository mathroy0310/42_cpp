/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:25:30 by maroy             #+#    #+#             */
/*   Updated: 2024/03/06 00:30:26 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void tests_form(void) {
    std::cout << COLOR_CYAN << "# TEST PresidentialPardonForm creation #" << COLOR_RESET << std::endl;
    try {
        PresidentialPardonForm f1("default");
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST RobotomyRequestForm creation #" << COLOR_RESET << std::endl;
    try {
        RobotomyRequestForm f2("default");
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST ShrubberyCreationForm creation #" << COLOR_RESET << std::endl;
    try {
        ShrubberyCreationForm f3("default");
        std::cout << f3 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST PresidentialPardonForm execution #" << COLOR_RESET << std::endl;
    try {
        PresidentialPardonForm f1("default");
        Bureaucrat b1("Buro", 1);
        f1.beSigned(b1);
        f1.execute(b1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST RobotomyRequestForm execution #" << COLOR_RESET << std::endl;
    try {
        RobotomyRequestForm f2("default");
        Bureaucrat b2("Buro", 1);
        f2.beSigned(b2);
        f2.execute(b2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST RobotomyRequestForm execution #" << COLOR_RESET << std::endl;
    try {
        RobotomyRequestForm f2("default");
        Bureaucrat b2("Buro", 1);
        f2.beSigned(b2);
        f2.execute(b2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST ShrubberyCreationForm execution #" << COLOR_RESET << std::endl;
    try {
        ShrubberyCreationForm f3("default");
        Bureaucrat b3("Buro", 1);
        f3.beSigned(b3);
        f3.execute(b3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}