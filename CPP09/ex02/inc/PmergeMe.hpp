/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:29:49 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/22 04:00:03 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <climits>
#include <sys/time.h>

class PmergeMe {
private:
    std::vector<int> vect;
    std::deque<int> deque;
    double time_deque;
    double time_vector;
    double time_input;

    template <typename Container>
    void merge(Container& cont, int first, int mid, int second);

    template <typename Container>
    void mergeInsertionSort(Container& cont, int first, int second);

    template <typename Container>
    void insertionSort(Container& cont, int first, int last);

    template <typename Container>
    void algoContainer(Container& cont, double& time);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void addInput(int argc, char **argv);
    void run();
    void printVector();
    void printInfoV();
    void printDeque();
    void printInfoD();
};

#include "PmergeMe.tpp"
