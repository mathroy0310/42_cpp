/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:07:47 by maroy             #+#    #+#             */
/*   Updated: 2024/07/29 15:54:09 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>

#include "Span.hpp"

#define PRINT(x) std::cout << std::boolalpha << x << std::endl;
#define PUT_DELIM std::cout << std::string(40, '-') << std::endl;
#define PUT_HEADER(x) \
    std::cout << std::string(40, '*') << std::endl << "TEST : " << x << std::endl << std::string(40, '*') << std::endl;

void test_subject() {
    PUT_HEADER("Subject")
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    PRINT("shortestSpan: " << sp.shortestSpan());
    PRINT("longestSpan: " << sp.longestSpan());
    PRINT('\n');
}

void test_invalid_addNumber() {
    PUT_HEADER("invalid addNumber")
    try {
        Span sp = Span(1);
        sp.addNumber(1);
        sp.addNumber(2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    PRINT('\n');
}

void test_invalid_shortestSpan() {
    PUT_HEADER("invalid shortestSpan")
    try {
        Span sp = Span(1);
        PRINT("shortestSpan: " << sp.shortestSpan());
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Span sp = Span(1);
        sp.addNumber(1);
        PUT_DELIM
        PRINT("shortestSpan: " << sp.shortestSpan());
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    PRINT('\n');
}

void test_invalid_longestSpan() {
    PUT_HEADER("invalid longestSpan")
    try {
        Span sp = Span(1);
        PRINT("longestSpan: " << sp.longestSpan());
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Span sp = Span(1);
        sp.addNumber(1);
        PUT_DELIM
        PRINT("longestSpan: " << sp.longestSpan());
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    PRINT('\n');
}

void test_big_number() {
    PUT_HEADER("Test big number")
    try {
        Span sp = Span(50000);
        sp.addNumber(5);
        for (int i = 1000; i < 40000; i++) {
            sp.addNumber(i);
        }
        PUT_DELIM;
        PRINT("shortestSpan: " << sp.shortestSpan());
        PRINT("longestSpan: " << sp.longestSpan());
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    PRINT('\n');
}

void test_invalid_range() {
    PUT_HEADER("invalid range")
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        Span sp = Span(1);
        sp.addRange(vec.begin(), vec.end());
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::vector<int> vec;
        vec.push_back(1);
        Span sp = Span(1);
        sp.addRange(vec.begin(), vec.end());
        sp.showNumbers();
        PUT_DELIM;
        PRINT("shortestSpan: " << sp.shortestSpan());
        PRINT("longestSpan: " << sp.longestSpan());
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    PRINT('\n');
}

void test_valid_range() {
    PUT_HEADER("valid range")
    try {
        std::vector<int> vec;
        for (int i = 0; i < 5; i++) {
            vec.push_back(i);
        }
        Span sp = Span(5);
        sp.addRange(vec.begin(), vec.end());
        sp.showNumbers();
        PUT_DELIM;
        PRINT("shortestSpan: " << sp.shortestSpan());
        PRINT("longestSpan: " << sp.longestSpan());
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    PRINT('\n');
}

void test_copy_assignation() {
    PUT_HEADER("copy assignation")
    Span sp = Span(5);
    sp.addNumber(42);
    sp.addNumber(24);
    sp.addNumber(99);
    sp.showNumbers();
    Span sp2 = sp;
    PUT_DELIM;
    sp2.showNumbers();
    PRINT('\n');
}

void test_copy_constructor() {
    PUT_HEADER("copy constructor")
    Span sp = Span(5);
    sp.addNumber(42);
    sp.addNumber(24);
    sp.addNumber(99);
    sp.showNumbers();
    Span sp2(sp);
    PUT_DELIM;
    sp2.showNumbers();
    PRINT('\n');
}

int main() {
    test_subject();
    test_invalid_addNumber();
    test_invalid_shortestSpan();
    test_invalid_longestSpan();
    test_big_number();
    test_invalid_range();
    test_valid_range();
    test_copy_assignation();
    test_copy_constructor();

    return 0;
}
