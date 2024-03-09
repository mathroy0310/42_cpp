/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:54:14 by maroy             #+#    #+#             */
/*   Updated: 2024/03/09 16:34:43 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

	
    if (argc != 2) {
        std::cerr << COLOR_RED <<"Wong amount of arguments" << COLOR_RESET <<std::endl;
        return (1);
    }
    try {
        ScalarConverter conv(argv[1]);
		conv.printOutput();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
