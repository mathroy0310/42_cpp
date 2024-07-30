/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:42:56 by maroy             #+#    #+#             */
/*   Updated: 2024/07/29 15:36:53 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

#define COLOR_RESET "\x1b[0m"
#define COLOR_RED "\x1b[31m"
#define COLOR_CYAN "\x1b[36m"

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
        virtual const char *what() const throw();
    };
    class NoSpanExecption : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

#endif