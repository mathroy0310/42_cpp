/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:29:36 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/26 00:52:49 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv) {
    this->_vect.reserve(argc - 1);  // Reserve memory for vector
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
    this->_time_input = calculateTime(begin, end);
}

void PmergeMe::run() {
    std::cout << "Before: ";
    printContainer(this->_vect);
    sort(this->_vect, this->_time_vector);
    sort(this->_deque, this->_time_deque);
    std::cout << "After: ";
    printContainer(this->_deque);
    printInfo(this->_vect, "std::vector", this->_time_vector);
    printInfo(this->_deque, "std::deque", this->_time_deque);
}

double PmergeMe::calculateTime(const struct timeval &begin, const struct timeval &end) {
    long sec = end.tv_sec - begin.tv_sec;
    long msec = end.tv_usec - begin.tv_usec;
    return sec * 1e6 + msec;
}