/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:26:46 by maroy             #+#    #+#             */
/*   Updated: 2024/05/05 22:34:50 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void test_pdf(void);
template <typename T> void test(T &foo, T &bar);

template <typename T> void swap(T &a, T &b) {

    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T> T &min(T &a, T &b) {

    return (a < b ? a : b);
}

template <typename T> T &max(T &a, T &b) {

    return (a > b ? a : b);
}

int main(void) {

    test_pdf();

    std::cout << std::endl << std::endl;

    float c = 42.42, d = 21.21;
    test(c, d);

    char e = 'e', f = 'f';
    test(e, f);

    size_t g = 42, h = 21;
    test(g, h);

    double i = 42.42, j = 21.21;
    test(i, j);

    bool k = true, l = false;
    test(k, l);

    return (EXIT_SUCCESS);
}

void test_pdf(void) {
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

#define PRINT(x) std::cout << std::boolalpha << x << std::endl;
#define PUT_DELIM std::cout << std::string(40, '-') << std::endl;
#define PUT_HEADER(x)                                       \
    std::cout << std::string(40, '*') << std::endl          \
              << "TEST : " << typeid(x).name() << std::endl \
              << std::string(40, '*') << std::endl;

template <typename T> void test(T &foo, T &bar) {
    assert(typeid(foo) == typeid(bar));
    PUT_HEADER(foo)
    PRINT("foo = " << foo << ", bar = " << bar)
    PUT_DELIM
    ::swap(foo, bar);
    PRINT("swapped foo = " << foo << ", swapped bar = " << bar)
    PUT_DELIM
    ::swap(foo, bar);
    PRINT("foo = " << foo << ", bar = " << bar)
    PUT_DELIM
    PRINT("min( foo, bar ) = " << ::min(foo, bar))
    PUT_DELIM
    PRINT("max( foo, bar ) = " << ::max(foo, bar))
    PUT_DELIM
    PRINT('\n')
}
