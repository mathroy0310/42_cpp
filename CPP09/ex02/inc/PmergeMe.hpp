/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:29:49 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/26 00:29:17 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <climits>
#include <cstdlib>
#include <cstring>
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

    template <typename Container> void sort(Container &cont, double &time);
    
    template <typename Container>
    void createPairs(const Container &cont, std::vector<std::pair<int, int> > &pairs, Container &s);
    
    template <typename Container> void generateJacobsthalSequence(const Container &s, Container &jacobsthal);
    
    template <typename Container>
    typename Container::iterator binarySearch(Container &s, int value, typename Container::iterator begin, typename Container::iterator end);

    template <typename Container>
    void insertSort(std::vector<std::pair<int, int> > &pairs, Container &s, const Container &jacobsthal);

    double calculateTime(const struct timeval &begin, const struct timeval &end);

    template <typename Container> void printContainer(Container &cont) const;
    template <typename Container> void printInfo(Container &cont, std::string type, double time) const;

    PmergeMe();                                  // wont compile
    PmergeMe(const PmergeMe &other);             // wont compile
    PmergeMe &operator=(const PmergeMe &other);  // wont compile
  public:
    PmergeMe(int argc, char **argv);
    ~PmergeMe();

    void run();
};

#include "PmergeMe.tpp"
