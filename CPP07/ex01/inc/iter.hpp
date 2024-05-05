/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:43:05 by maroy             #+#    #+#             */
/*   Updated: 2024/05/04 19:51:19 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
#include <sstream>
#include <iomanip>
	
template< typename T, size_t N >
void test(T (&x)[N]);
template< size_t N >
void test(std::string (&x)[N]);
template< size_t N >
void test(int (&x)[N]);
template< size_t N >
void test(char (&x)[N]);

#endif // ITER_HPP
