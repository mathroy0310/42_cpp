/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:35:22 by maroy             #+#    #+#             */
/*   Updated: 2024/05/10 14:11:27 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {
  private:
    T *_arr;
    unsigned int _arr_size;

  public:
    Array();
    ~Array();
    Array(unsigned int n);
    Array(const Array &anotherArr);
    Array &operator=(const Array &anotherArr);
    T &operator[](unsigned int index);
    unsigned int size() const;
    class IndexOutOfBoundsException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

#include "Array.tpp"

#endif