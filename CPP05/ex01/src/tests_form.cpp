/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:25:30 by maroy             #+#    #+#             */
/*   Updated: 2024/05/02 13:51:32 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void tests_form(void) {
    std::cout << COLOR_CYAN << "# TEST over 150 grade #" << COLOR_RESET << std::endl;
    try {
        Form f2("Form2", 400, 1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST under 1 grade #" << COLOR_RESET << std::endl;
    try {
        Form f1("Form1", -123, 1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST sign failed too low #" << COLOR_RESET << std::endl;
    try {
        Form f3("Form3", 1, 1);
        Bureaucrat b3("Buro", 150);
        b3.signForm(f3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST sign success #" << COLOR_RESET << std::endl;
    try {
        Form f4("Form4", 1, 1);
        Bureaucrat b4("Buro", 1);
        b4.signForm(f4);
		std::cout << b4 << std::endl;
        std::cout << f4 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST beSigned #" << COLOR_RESET << std::endl;
    try {
        Form f5("Form5", 1, 1);
        Bureaucrat b5("Buro", 1);
        f5.beSigned(b5);
		std::cout << b5 << std::endl;
        std::cout << f5 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST form already signed#" << COLOR_RESET << std::endl;
    try {
        Form f6("Form6", 150, 1);
        Bureaucrat b6("Buro", 150);
        b6.signForm(f6);
        b6.signForm(f6);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST signForm failed too low  #" << COLOR_RESET << std::endl;
    try {
        Form f6("Form6", 5, 5);
        Bureaucrat b6("Buro", 10);
        b6.signForm(f6);
		std::cout << b6 << std::endl;
        std::cout << f6 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}
