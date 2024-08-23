/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:29:19 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/23 13:17:06 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//
//  `shuf -i 1-100000 -n 3000 | tr "\n" " "`
//

int main(int argc, char **argv) {
    if (argc <= 2)
      std::cerr << "Usage: ./PmergeMe [1 3 4 5 6]" << std::endl;
    else {
        try {
            PmergeMe pm(argc, argv);
            pm.run();
        } catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }
    return (0);
}