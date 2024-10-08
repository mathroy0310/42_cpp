/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:36:32 by maroy             #+#    #+#             */
/*   Updated: 2024/08/20 23:11:45 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//
//  https://www.dcode.fr/reverse-polish-notation
//  https://en.wikipedia.org/wiki/Reverse_Polish_notation
//  https://www.computersciencebytes.com/array-variables/reverse-polish-notation/
//  "2 3 + 4 *" == 20
//  "4  2  5  *  +  1  3  2  *  +  /" == 2
//

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN [expression]" << std::endl;
        return 1;
    }
    try {
        RPN rpn(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
