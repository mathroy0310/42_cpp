/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:17:00 by maroy             #+#    #+#             */
/*   Updated: 2024/05/05 22:29:42 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

/* ************************************************************************** */

template <typename T> void iter(T *array, size_t size, void (*f)(T &)) {

    for (size_t i = 0; i < size; i++)
        f(array[i]);
}

int main() {
    int tab[] = {0, 1, 2, 3, 4};
    test(tab);
    std::cout << std::endl;

    std::string tab2[] = {"miam", "des", "hot-dogs"};
    test(tab2);
    std::cout << std::endl;

    char tab3[] = {'7', ':', 51, '3', '0', 95, '(', '0', 45, 51, ';', '^'};
    test(tab3);
    std::cout << std::endl;
    return 0;
}

/* ************************************************************************** */

// TESTS //

/* ************************************************************************** */

#define PRINT(x) std::cout << std::boolalpha << x << " ";
#define PUT_NL std::cout << std::endl;
#define PUT_DELIM std::cout << std::string(40, '-') << std::endl;
#define PUT_HEADER(x)                                       \
    std::cout << std::string(40, '*') << std::endl          \
              << "TEST : " << typeid(x).name() << std::endl \
              << std::string(40, '*') << std::endl;

template <typename T> void test_print(T &elem) {
    PRINT(elem)
}

void test_to_upper(std::string &elem) {
    std::transform(elem.begin(), elem.end(), elem.begin(), ::toupper);
}

void test_mirror_ascii(char &elem) {
    elem = 127 - elem;
}
template <typename T> void test_increment(T &elem) {
    elem++;
}

template <size_t N> void test(std::string (&x)[N]) {
    PUT_HEADER(x)
    iter(x, N, test_print);
    PUT_NL
    PUT_DELIM
    iter(x, N, test_to_upper);
    iter(x, N, test_print);
    PUT_NL
}

template <size_t N> void test(int (&x)[N]) {
    PUT_HEADER(x)
    iter(x, N, test_print);
    PUT_NL
    PUT_DELIM
    while (*x < 10)
        iter(x, N, test_increment);
    iter(x, N, test_print);
    PUT_NL
}

template <size_t N> void test(char (&x)[N]) {
    PUT_HEADER(x)
    iter(x, N, test_print);
    PUT_NL
    PUT_DELIM
    iter(x, N, test_mirror_ascii);
    iter(x, N, test_print);
    PUT_NL
}
/* ************************************************************************** */
