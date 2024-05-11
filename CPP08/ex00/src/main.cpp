/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:07:47 by maroy             #+#    #+#             */
/*   Updated: 2024/05/10 14:37:45 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <typeinfo>
#include <list>
#include <vector>

#define PRINT(x) std::cout << std::boolalpha << x << std::endl;
#define PUT_DELIM std::cout << std::string(40, '-') << std::endl;
#define PUT_HEADER(x)                                       \
    std::cout << std::string(40, '*') << std::endl          \
              << "TEST : " << typeid(x).name() << std::endl \
              << std::string(40, '*') << std::endl;

int main(void) {

    int elem_to_find;
    std::vector<int> vec(7, 5);
    {
        elem_to_find = 5;
        PUT_HEADER(vec);
        PRINT("Container Size = " << vec.size())
        PRINT("Elem to find: " << elem_to_find);
        try {
            easyfind(vec, 5);
        } catch (std::exception &e) {
            std::cout << e.what() << ": " << elem_to_find << std::endl;
        }
    }
    {
        elem_to_find = 6;
        PUT_HEADER(vec);
        PRINT("Container Size = " << vec.size())
        PRINT("Elem to find: " << elem_to_find);
        try {
            easyfind(vec, 6);
        } catch (std::exception &e) {
            std::cout << e.what() << ": " << elem_to_find << std::endl;
        }
    }
    std::list<int> lst;

    lst.push_back(3);
    lst.push_back(45);
    lst.push_back(8);
    lst.push_back(12);
    lst.push_back(20);
    {
        elem_to_find = 8;
        PUT_HEADER(lst);
        PRINT("Container Size = " << lst.size())
        PRINT("Elem to find: " << elem_to_find);
        try {
            easyfind(lst, elem_to_find);
        } catch (std::exception &e) {
            std::cout << e.what() << ": " << elem_to_find << std::endl;
        }
    }
    {
        elem_to_find = 18;
        PUT_HEADER(lst);
        PRINT("Container Size = " << lst.size())
        PRINT("Elem to find: " << elem_to_find);
        try {
            easyfind(lst, elem_to_find);
        } catch (std::exception &e) {
            std::cout << e.what() << ": " << elem_to_find << std::endl;
        }
    }

    return 0;
}
