/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_bureaucrat.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:24:22 by maroy             #+#    #+#             */
/*   Updated: 2024/03/05 15:25:47 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void tests_bureaucrat(void) {
    // TEST over 150 echelon
    std::cout << COLOR_CYAN << "# TEST over 150 echelon #" << COLOR_RESET << std::endl;
    try {
        Bureaucrat b2("Buro", 400);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST under 1 echelon #" << COLOR_RESET << std::endl;
    try {
        Bureaucrat b1("Buro", -123);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST increment  under 1 #" << COLOR_RESET << std::endl;
    try {
        Bureaucrat b3("Buro", ECHELON_MIN);
        b3.incrementEchelon();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST decrement over 150 #" << COLOR_RESET << std::endl;
    try {
        Bureaucrat b4("Buro", ECHELON_MAX);
        b4.decrementEchelon();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST decrement to show it works #" << COLOR_RESET << std::endl;
    try {
        std::string name = "Buro6";
        Bureaucrat b6(name, 130);
        b6.decrementEchelon();
        std::cout << b6 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST increment to show it works #" << COLOR_RESET << std::endl;
    try {
        std::string name = "Buro";
        Bureaucrat b5(name, 140);
        b5.incrementEchelon();
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
}
