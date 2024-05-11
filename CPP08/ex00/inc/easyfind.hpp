/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:09:07 by maroy             #+#    #+#             */
/*   Updated: 2024/05/10 14:35:00 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

class NotFound : public std::exception {
  public:
    virtual const char *what() const throw() { return ("ERROR: Element not found"); };
};

template <typename T> void easyfind(T &container, int value);

#include "easyfind.tpp"

#endif  // EASYFIND_HPP
