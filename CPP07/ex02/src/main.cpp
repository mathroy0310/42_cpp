/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:04:50 by rchahban          #+#    #+#             */
/*   Updated: 2024/05/10 14:12:44 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <typeinfo>

#define PRINT(x) std::cout << std::boolalpha << x << std::endl;
#define PUT_DELIM std::cout << std::string(40, '-') << std::endl;
#define PUT_HEADER(x)                                       \
    std::cout << std::string(40, '*') << std::endl          \
              << "TEST : " << typeid(x).name() << std::endl \
              << std::string(40, '*') << std::endl;

template <typename T> void testArray(Array<T> &arr) {
    PUT_HEADER(arr)
    PRINT("Array size = " << arr.size())
    PUT_DELIM
    try {
        for (unsigned int i = 0; i < arr.size(); i++) {
            PRINT("arr[" << i << "] = " << arr[i])
        }
    } catch (typename Array<T>::IndexOutOfBoundsException &e) {
        std::cout << e.what() << std::endl;
    }
    PUT_DELIM
}

int main(void) {
    PRINT('\n') {
        Array<int> intArr(5);
        for (unsigned int i = 0; i < intArr.size(); i++) {
            intArr[i] = i * 10;
        }
        testArray(intArr);
    }
    PRINT('\n') {
        Array<float> floatArr(5);
        for (unsigned int i = 0; i < floatArr.size(); i++) {
            floatArr[i] = i * 1.1f;
        }
        testArray(floatArr);
    }
    PRINT('\n') {
        Array<std::string> stringArr(5);
        for (unsigned int i = 0; i < stringArr.size(); i++) {
            std::stringstream ss;
            ss << "string" << i;
            stringArr[i] = ss.str();
        }
        testArray(stringArr);
    }
    PRINT('\n') {
        Array<std::string> stringArr(15);
        for (unsigned int i = 0; i < stringArr.size(); i++) {
            std::stringstream ss;
            ss << "big_string" << i;
            stringArr[i] = ss.str();
        }
        testArray(stringArr);
    }

    return (EXIT_SUCCESS);
}
