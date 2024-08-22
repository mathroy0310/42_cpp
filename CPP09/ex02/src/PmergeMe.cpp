/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:29:36 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/22 04:00:03 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    std::cout << "PmergeMe copy" << std::endl;   
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    std::cout << "PmergeMe copy assignment" << std::endl;
    if (this != &other) {
        this->vect = other.vect;
        this->deque = other.deque;
        this->time_deque = other.time_deque;
        this->time_vector = other.time_vector;
        this->time_input = other.time_input;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::addInput(int argc, char **argv) {
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos)
            throw std::invalid_argument("Error : Value must be a number");
        char *end;
        long num = std::strtol(argv[i], &end, 10);
        if (*end != '\0' || num < 0)
            throw std::invalid_argument("Error : Value must be positive");
        if (num > INT_MAX)
             throw std::invalid_argument("Error : Value must be in INT range");
        vect.push_back(static_cast<int>(num));
        deque.push_back(static_cast<int>(num));
    }
    gettimeofday(&end, 0);
    long sec = end.tv_sec - begin.tv_sec;
    long msec = end.tv_usec - begin.tv_usec;
    double timer = sec * 1e6 + msec;
    time_input = timer;
}
void    PmergeMe::run()
{
    std::cout << "Before: ";
    printVector();
    algoContainer(vect, time_vector);
    algoContainer(deque, time_deque);
    std::cout << "After: ";
    printDeque();   
    printInfoV();
    printInfoD();
}

void PmergeMe::printVector() {
    for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it) {
        std::cout << *it << " ";
    } 
    std::cout << std::endl;  
}

void PmergeMe::printInfoV() {
    std::cout << "Time to process a range of " << vect.size() << " elements with std::vector : ";
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << time_vector << " us (" << time_vector / 1e6 << " s)" << std::endl;
}

void PmergeMe::printDeque() {
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printInfoD() {
    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : ";
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << time_deque << " us (" << time_deque / 1e6 << " s)" << std::endl;
}