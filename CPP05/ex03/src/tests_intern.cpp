/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_intern.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:02:46 by maroy             #+#    #+#             */
/*   Updated: 2024/05/02 15:18:20 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define PRESIDENTIAL_FORM "presidential pardon"
#define ROBOTOMY_FORM "robotomy request"
#define SHRUBBERY_FORM "shrubbery creation"

void tests_intern(void) {
    std::cout << COLOR_CYAN << "# TEST Intern FAIL not found #" << COLOR_RESET << std::endl;
    try {
        Intern i;
        AForm *f1 = i.makeForm("bozo deez nuts", "default");
        delete f1;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST Intern FAIL Robotomy #" << COLOR_RESET << std::endl;
    try {
        Intern i;
        Bureaucrat b1("b1", 1);
        AForm *f1 = i.makeForm(ROBOTOMY_FORM, "allo");
        b1.signForm(*f1);
        b1.executeForm(*f1);
        delete f1;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST Intern Presidential #" << COLOR_RESET << std::endl;
    try {
        Intern i;
        Bureaucrat b1("b1", 1);
        AForm *f1 = i.makeForm(PRESIDENTIAL_FORM, "allo");
        b1.signForm(*f1);
        b1.executeForm(*f1);
        delete f1;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST Intern shrubbery #" << COLOR_RESET << std::endl;
    try {
        Intern i;
        Bureaucrat b1("b1", 1);
        AForm *f1 = i.makeForm(SHRUBBERY_FORM, "allo");
        b1.signForm(*f1);
        b1.executeForm(*f1);
        delete f1;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

	std::cout << COLOR_CYAN << "# TEST Intern RObotomy Grade too low #" << COLOR_RESET << std::endl;
    try {
        Intern i;
        Bureaucrat b1("b1", 140);
        AForm *f1 = i.makeForm(ROBOTOMY_FORM, "allo");
        b1.signForm(*f1);
        delete f1;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST Intern Presidential Grade too low #" << COLOR_RESET << std::endl;
    try {
        Intern i;
        Bureaucrat b1("b1", 140);
        AForm *f1 = i.makeForm(PRESIDENTIAL_FORM, "allo");
        b1.signForm(*f1);
        delete f1;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST Intern shrubbery Grade too low #" << COLOR_RESET << std::endl;
    try {
        Intern i;
        Bureaucrat b1("b1", 150);
        AForm *f1 = i.makeForm(SHRUBBERY_FORM, "allo");
        b1.signForm(*f1);
        delete f1;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

	std::cout << COLOR_CYAN << "# TEST Intern RObotomy Not signed #" << COLOR_RESET << std::endl;
    try {
        Intern i;
        Bureaucrat b1("b1", 140);
        AForm *f1 = i.makeForm(ROBOTOMY_FORM, "allo");
        b1.executeForm(*f1);
        delete f1;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST Intern Presidential Not signed #" << COLOR_RESET << std::endl;
    try {
        Intern i;
        Bureaucrat b1("b1", 140);
        AForm *f1 = i.makeForm(PRESIDENTIAL_FORM, "allo");
        b1.executeForm(*f1);
        delete f1;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST Intern shrubbery Not signed #" << COLOR_RESET << std::endl;
    try {
        Intern i;
        Bureaucrat b1("b1", 150);
        AForm *f1 = i.makeForm(SHRUBBERY_FORM, "allo");
        b1.executeForm(*f1);
        delete f1;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}
