/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:42:19 by maroy             #+#    #+#             */
/*   Updated: 2024/07/29 15:53:23 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int size) {
    this->_vec.reserve(size);
}

Span::Span(const Span &src) {
    *this = src;
}

Span::~Span() {}

Span &Span::operator=(const Span &src) {
    this->_vec.reserve(src._vec.capacity());
    this->_vec = src._vec;
    return *this;
}

void Span::addNumber(int n) {
    if (this->_vec.size() == this->_vec.capacity())
        throw FullException();
    this->_vec.push_back(n);
}

void Span::addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end) {
    if (static_cast<unsigned long>(std::distance(beg, end)) > this->_vec.capacity() - this->_vec.size())
        throw FullException();
    this->_vec.insert(this->_vec.end(), beg, end);
}

int Span::shortestSpan() const {
    if (this->_vec.size() <= 1)
        throw NoSpanExecption();
    std::vector<int> tmp(this->_vec);
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size(); i++) {
        int span = tmp[i] - tmp[i - 1];
        if (span < min)
            min = span;
    }
    return min;
}

int Span::longestSpan() const {
    if (this->_vec.size() <= 1)
        throw NoSpanExecption();
    std::vector<int> tmp(this->_vec);
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

void Span::showNumbers() const {
    for (size_t i = 0; i < this->_vec.size(); i++) {
        std::cout << "vec[" << i << "] = " << this->_vec[i] << std::endl;
    }
    // Show capacity and size
    std::cout << "capacity = " << this->_vec.capacity() << std::endl;
    std::cout << "size = " << this->_vec.size() << std::endl;
}

const char *Span::FullException::what() const throw() {
    return (COLOR_RED "ERROR : Span is Full" COLOR_RESET);
}

const char *Span::NoSpanExecption::what() const throw() {
    return (COLOR_RED "ERROR : No Span to find" COLOR_RESET);
}