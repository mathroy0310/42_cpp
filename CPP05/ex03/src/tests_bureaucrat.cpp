/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_bureaucrat.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:24:22 by maroy             #+#    #+#             */
/*   Updated: 2024/03/06 14:35:11 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void tests_bureaucrat(void) {
    // TEST over 150 grade
    std::cout << COLOR_CYAN << "# TEST over 150 grade #" << COLOR_RESET << std::endl;
    try {
        Bureaucrat b2("Buro", 400);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST under 1 grade #" << COLOR_RESET << std::endl;
    try {
        Bureaucrat b1("Buro", -123);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST increment  under 1 #" << COLOR_RESET << std::endl;
    try {
        Bureaucrat b3("Buro", GRADE_MIN);
        b3.incrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST decrement over 150 #" << COLOR_RESET << std::endl;
    try {
        Bureaucrat b4("Buro", GRADE_MAX);
        b4.decrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST decrement to show it works #" << COLOR_RESET << std::endl;
    try {
        std::string name = "Buro6";
        Bureaucrat b6(name, 130);
        b6.decrementGrade();
        std::cout << b6 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST increment to show it works #" << COLOR_RESET << std::endl;
    try {
        std::string name = "Buro";
        Bureaucrat b5(name, 140);
        b5.incrementGrade();
        std::cout << b5 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST copy constructor #" << COLOR_RESET << std::endl;
    try {
        std::string name = "Buro";
        Bureaucrat b7(name, 140);
        Bureaucrat b8(b7);
        std::cout << b8 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST execute Presidential FAIL grade#" << COLOR_RESET << std::endl;
    try {
        std::string name = "alloPresidential";
        Bureaucrat b9(name, 140);
        PresidentialPardonForm f10("f10");
        b9.executeForm(f10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST execute Robotomy FAIL grade#" << COLOR_RESET << std::endl;
    try {
        std::string name = "alloRobotomy";
        Bureaucrat b9(name, 140);
        RobotomyRequestForm f10("f10");
        b9.executeForm(f10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST execute Shrubbery FAIL grade #" << COLOR_RESET << std::endl;
    try {
        std::string name = "alloShrubbery";
        Bureaucrat b9(name, 140);
        ShrubberyCreationForm f10("f10");
        b9.executeForm(f10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST execute Presidential FAIL signed #" << COLOR_RESET << std::endl;
    try {
        std::string name = "alloPresidential";
        Bureaucrat b9(name, 1);
        PresidentialPardonForm f10("f10");
        b9.executeForm(f10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST execute Robotomy FAIL signed #" << COLOR_RESET << std::endl;
    try {
        std::string name = "alloRobotomy";
        Bureaucrat b9(name, 1);
        RobotomyRequestForm f10("f10");
        b9.executeForm(f10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST execute Shrubbery FAIL signed #" << COLOR_RESET << std::endl;
    try {
        std::string name = "alloShrubbery";
        Bureaucrat b9(name, 1);
        ShrubberyCreationForm f10("f10");
        b9.executeForm(f10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST execute Presidential #" << COLOR_RESET << std::endl;
    try {
        std::string name = "alloPresidential";
        Bureaucrat b9(name, 1);
        PresidentialPardonForm f10("f10");
        f10.beSigned(b9);
        b9.executeForm(f10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST execute Robotomy #" << COLOR_RESET << std::endl;
    try {
        std::string name = "alloRobotomy";
        Bureaucrat b9(name, 1);
        RobotomyRequestForm f10("f10");
        f10.beSigned(b9);
        b9.executeForm(f10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST execute Shrubbery #" << COLOR_RESET << std::endl;
    try {
        std::string name = "alloShrubbery";
        Bureaucrat b9(name, 1);
        ShrubberyCreationForm f10("f10");
        f10.beSigned(b9);
        b9.executeForm(f10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
}
