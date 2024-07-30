/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:07:47 by maroy             #+#    #+#             */
/*   Updated: 2024/07/29 15:22:30 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <typeinfo>
#include <vector>

#define PRINT(x) std::cout << std::boolalpha << x << std::endl;
#define PUT_DELIM std::cout << std::string(40, '-') << std::endl;
#define PUT_HEADER(x)                                       \
    std::cout << std::string(40, '*') << std::endl          \
              << "TEST : " << typeid(x).name() << std::endl \
              << std::string(40, '*') << std::endl;

int main(void) {

    int nb_to_find;
    std::vector<int> vec(7, 5);  // remplis vecteur de 7 fois valeur 5
    {
        nb_to_find = 5;
        PUT_HEADER(vec);
        PRINT("Container Size = " << vec.size())
        PRINT("Elem to find: " << nb_to_find);
        try {
            easyfind(vec, nb_to_find);
        } catch (std::exception &e) {
            std::cout << e.what() << ": " << nb_to_find << std::endl;
        }
    }
    PRINT("\n") {
        nb_to_find = 6;
        PUT_HEADER(vec);
        PRINT("Container Size = " << vec.size())
        PRINT("Elem to find: " << nb_to_find);
        try {
            easyfind(vec, nb_to_find);
        } catch (std::exception &e) {
            std::cout << e.what() << ": " << nb_to_find << std::endl;
        }
    }
    PRINT("\n")
    std::list<int> lst;  // declare la liste vide

    // ajoute des elements a la liste un a la fois
    lst.push_back(3);
    lst.push_back(45);
    lst.push_back(8);
    lst.push_back(12);
    lst.push_back(20);
    {
        nb_to_find = 8;
        PUT_HEADER(lst);
        PRINT("Container Size = " << lst.size())
        PRINT("Elem to find: " << nb_to_find);
        try {
            easyfind(lst, nb_to_find);
        } catch (std::exception &e) {
            std::cout << e.what() << ": " << nb_to_find << std::endl;
        }
    }
    PRINT("\n") {
        nb_to_find = 18;
        PUT_HEADER(lst);
        PRINT("Container Size = " << lst.size())
        PRINT("Elem to find: " << nb_to_find);
        try {
            easyfind(lst, nb_to_find);
        } catch (std::exception &e) {
            std::cout << e.what() << ": " << nb_to_find << std::endl;
        }
    }
    PRINT("\n")
    return 0;
}
