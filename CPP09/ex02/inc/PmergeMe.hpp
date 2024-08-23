/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:29:49 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/23 14:28:26 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <climits>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sys/time.h>
#include <vector>

class PmergeMe {
  private:
    std::vector<int> _vect;
    std::deque<int> _deque;
    double _time_deque;
    double _time_vector;
    double _time_input;

    void addInput(int argc, char **argv);

    template <typename Container> void merge(Container &cont, int first, int mid, int second);

    template <typename Container> void mergeInsertionSort(Container &cont, int first, int second);

    template <typename Container> void insertionSort(Container &cont, int first, int last);

    template <typename Container> void algoContainer(Container &cont, double &time);

    template <typename Container> void printContainer(Container &cont);

    template <typename Container> void printInfo(Container &cont, std::string type, double time);

    PmergeMe();                                  // wont compile
    PmergeMe(const PmergeMe &other);             // wont compile
    PmergeMe &operator=(const PmergeMe &other);  // wont compile
  public:
    PmergeMe(int argc, char **argv);
    ~PmergeMe();

    void run();
};

#include "PmergeMe.tpp"
