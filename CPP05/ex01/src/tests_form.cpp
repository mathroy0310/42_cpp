/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:25:30 by maroy             #+#    #+#             */
/*   Updated: 2024/03/05 16:48:22 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void tests_form(void) {
    std::cout << COLOR_CYAN << "# TEST over 150 echelon #" << COLOR_RESET << std::endl;
    try {
        Form f2("Form2", 400, 1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST under 1 echelon #" << COLOR_RESET << std::endl;
    try {
        Form f1("Form1", -123, 1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST sign failed #" << COLOR_RESET << std::endl;
    try {
        Form f3("Form3", 1, 1);
        Bureaucrat b3("Buro", 150);
        b3.beSigned(f3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST sign success #" << COLOR_RESET << std::endl;
    try {
        Form f4("Form4", 1, 1);
        Bureaucrat b4("Buro", 1);
        b4.beSigned(f4);
        std::cout << f4 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST signForm #" << COLOR_RESET << std::endl;
    try {
        Form f5("Form5", 1, 1);
        Bureaucrat b5("Buro", 1);
        f5.signForm(b5);
        std::cout << f5 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST signForm failed #" << COLOR_RESET << std::endl;
    try {
        Form f6("Form6", 150, 1);
        Bureaucrat b6("Buro", 150);
        b6.beSigned(f6);
        b6.beSigned(f6);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST signForm failed too low  #" << COLOR_RESET << std::endl;
    try {
        Form f6("Form6", 5, 5);
        Bureaucrat b6("Buro", 10);
        b6.beSigned(f6);
        std::cout << f6 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}
