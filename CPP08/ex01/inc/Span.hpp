/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:42:56 by maroy             #+#    #+#             */
/*   Updated: 2024/05/10 20:11:20 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class Span {
  public:
    Span();
    Span(unsigned int size);
    Span(const Span &src);
    ~Span();
    Span &operator=(const Span &src);

    void addNumber(int n);
    void addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end);
    int shortestSpan() const;
    int longestSpan() const;
    void showNumbers() const;

  private:
    std::vector<int> _vec;

    class FullException : public std::exception {
      public:
        virtual const char *what() const throw() { return "Span is Full"; }
    };
    class NoSpanExecption : public std::exception {
      public:
        virtual const char *what() const throw() { return "No span to find"; }
    };
};

#endif