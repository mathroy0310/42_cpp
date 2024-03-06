/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:41:04 by maroy             #+#    #+#             */
/*   Updated: 2024/03/06 00:23:58 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void tests_bureaucrat(void);
void tests_form(void);

int main() {
    std::cout << "\n################################################\n" << std::endl;
    tests_bureaucrat();
    std::cout << "\n################################################\n" << std::endl;
    tests_form();
    std::cout << "\n################################################\n" << std::endl;
    return (0);
}
