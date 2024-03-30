/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:39:42 by maroy             #+#    #+#             */
/*   Updated: 2024/03/30 16:59:48 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

#define YELLOW "\033[2;33m"
#define RED "\033[2;31m"
#define CYAN "\033[2;36m"
#define DEF "\033[0m"

Base *generate(void) {

    srand(time(NULL));
    int random = rand() % 3;

    switch (random) {
    case 0:
        return (new A());
    case 1:
        return (new B());
    default:
        return (new C());
    }
}

void identify_from_pointer(Base *p) {

    if (dynamic_cast<A *>(p))
        std::cout << YELLOW << "A" << DEF << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << YELLOW << "B" << DEF << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << YELLOW << "C" << DEF << std::endl;
}

void identify_from_reference(Base &p) {

    try {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << RED << "A" << DEF << std::endl;
    } catch (std::bad_cast &bc) {
        try {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << RED << "B" << DEF << std::endl;
        } catch (std::bad_cast &bc) {
            try {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << RED << "C" << DEF << std::endl;
            } catch (std::bad_cast &bc) {
                std::cerr << RED << "Unknown" << DEF << std::endl;
            }
        }
    }
}

int main() {

    Base *base = generate();

    std::cout << CYAN << "Identify from pointer: " << DEF;
    identify_from_pointer(base);
    std::cout << CYAN << "Identify from reference: " << DEF;
    identify_from_reference(*base);

    delete base;
    return (0);
}