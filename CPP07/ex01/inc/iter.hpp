/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:43:05 by maroy             #+#    #+#             */
/*   Updated: 2024/05/05 22:29:45 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iomanip>
#include <iostream>
#include <sstream>

template <typename T, size_t N> void test(T (&x)[N]);
template <size_t N> void test(std::string (&x)[N]);
template <size_t N> void test(int (&x)[N]);
template <size_t N> void test(char (&x)[N]);

#endif  // ITER_HPP
