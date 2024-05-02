/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:41:04 by maroy             #+#    #+#             */
/*   Updated: 2024/05/02 13:05:18 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
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
        Bureaucrat b1("Buro", -132);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST increment  under 1 #" << COLOR_RESET << std::endl;
    try {
        Bureaucrat b3("Buro", ECHELON_MAX);
        b3.incrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << COLOR_CYAN << "# TEST decrement over 150 #" << COLOR_RESET << std::endl;
    try {
        Bureaucrat b4("Buro", ECHELON_MIN);
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

    return (0);
}
