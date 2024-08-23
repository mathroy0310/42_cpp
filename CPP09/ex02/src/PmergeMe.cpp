/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:29:36 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/23 14:28:55 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv) {
    this->_vect.reserve(argc - 1);  // Reserve memory for vector
    this->_deque.resize(argc - 1);  // Reserve memory for _deque

    addInput(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &other) {
    std::cout << "PmergeMe copy" << std::endl;
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    std::cout << "PmergeMe copy assignment" << std::endl;
    if (this != &other) {
        this->_vect = other._vect;
        this->_deque = other._deque;
        this->_time_deque = other._time_deque;
        this->_time_vector = other._time_vector;
        this->_time_input = other._time_input;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::addInput(int argc, char **argv) {
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    for (int i = 1; i < argc; i++) {
        const char *arg = argv[i];
        if (*arg == '\0' || std::strspn(arg, "0123456789") != std::strlen(arg))
            throw std::invalid_argument("Error: Value must be a number");

        char *end;
        long num = std::strtol(arg, &end, 10);
        if (*end != '\0' || num < 0)
            throw std::invalid_argument("Error : Value must be positive");
        if (num > INT_MAX)
            throw std::invalid_argument("Error : Value must be in INT range");
        int value = static_cast<int>(num);
        _vect.push_back(value);
        _deque.push_back(value);
    }
    gettimeofday(&end, 0);
    long sec = end.tv_sec - begin.tv_sec;
    long msec = end.tv_usec - begin.tv_usec;
    double timer = sec * 1e6 + msec;
    this->_time_input = timer;
}
void PmergeMe::run() {
    std::cout << "Before: ";
    printContainer(this->_vect);
    algoContainer(this->_vect, this->_time_vector);
    algoContainer(this->_deque, this->_time_deque);
    std::cout << "After: ";
    printContainer(this->_deque);
    printInfo(this->_vect, "std::vector", this->_time_vector);
    printInfo(this->_deque, "std::_deque", this->_time_deque);
}