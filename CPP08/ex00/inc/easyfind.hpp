/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:09:07 by maroy             #+#    #+#             */
/*   Updated: 2024/07/29 15:21:51 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

class NotFound : public std::exception {
  public:
    virtual const char *what() const throw() { return ("\x1b[31;1mERROR: Element not found\x1b[0m"); };
};

template <typename T> void easyfind(T &container, int value);

#include "easyfind.tpp"

#endif  // EASYFIND_HPP
