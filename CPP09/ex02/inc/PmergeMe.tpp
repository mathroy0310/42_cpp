/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 03:15:59 by maroy             #+#    #+#             */
/*   Updated: 2024/08/26 01:02:23 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <utility>

template <typename Container> void PmergeMe::sort(Container &cont, double &time) {
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    std::vector<std::pair<int, int> > pairs;
    Container s;
    Container jacobsthal;

    createPairs(cont, pairs, s);
    std::sort(s.begin(), s.end());
    this->printContainer(s);
    generateJacobsthalSequence(s, jacobsthal);
    insertSort(pairs, s, jacobsthal);

    cont = s;

    gettimeofday(&end, 0);
    time = _time_input + calculateTime(begin, end);
}

template <typename Container>
void PmergeMe::createPairs(const Container &cont, std::vector<std::pair<int, int> > &pairs, Container &s) {
    size_t i;
    for (i = 0; i + 1 < cont.size(); i += 2) {
        std::pair<int, int> pair;
        pair.first = cont[i];
        pair.second = cont[i + 1];

        if (pair.first < pair.second) {
            // mon propre swap plus rapide que std::swap environ 10 us
            int temp = pair.first;
            pair.first = pair.second;
            pair.second = temp;
        }
        pairs.push_back(pair);
        s.push_back(pair.first);
    }
    if (i < cont.size()) {
        s.push_back(cont[i]);
    }
}

template <typename Container> void PmergeMe::generateJacobsthalSequence(const Container &s, Container &jacobsthal) {
    // 0, 1, 3, 15, 55, 231, 903, 3655, 14535, 58311,  ... (jacobsthal[n - 1] + 2 * jacobsthal[n - 2])
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (jacobsthal[jacobsthal.size() - 1] < static_cast<int>(s.size())) {
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
    }
}

template <typename Container>
typename Container::iterator PmergeMe::binarySearch(Container &s, int value, typename Container::iterator begin, typename Container::iterator end) {
    (void)s;    
    while (begin < end) {
        typename Container::iterator mid 
            pair.first = pair.second;= begin + (end - begin) / 2;
        
        if (value < *mid)
            end = mid;
        else
            begin = mid + 1;
    }
    return begin;
}

template <typename Container>
void PmergeMe::insertSort(std::vector<std::pair<int, int> > &pairs, Container &s, const Container &jacobsthal) {
    size_t inserted = 1;  // We start with 1 as the first element is already in place
    for (size_t i = 1; i < jacobsthal.size() && inserted < pairs.size(); ++i) {
        size_t curr = jacobsthal[i];
        size_t prev = jacobsthal[i-1];
        for (size_t j = curr; j > prev && j <= pairs.size(); --j) {
            typename Container::iterator insertPos = binarySearch(s, pairs[j-1].second, s.begin(), s.begin() + inserted);
            s.insert(insertPos, pairs[j-1].second);
            inserted++;
        }
    }
    // Insert any remaining elements
    for (size_t i = inserted; i < pairs.size(); ++i) {
        typename Container::iterator insertPos = binarySearch(s, pairs[i].second, s.begin(), s.end());
        s.insert(insertPos, pairs[i].second);
    }
}

template <typename Container> void PmergeMe::printContainer(Container &cont) const {
    for (typename Container::const_iterator it = cont.begin(); it != cont.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container> void PmergeMe::printInfo(Container &cont, std::string type, double time) const {
    std::cout << "Time to process a range of " << cont.size() << " elements with " << type << " : ";
    std::cout << std::fixed;
    std::cout.precision(3);

    std::string unit;
    double displayTime;
    if (time < 1e3) {
        unit = " us";
        displayTime = time;
    } else if (time < 1e6) {
        unit = " ms";
        displayTime = time / 1e3;
    } else {
        unit = " s";
        displayTime = time / 1e6;
    }

    std::cout << displayTime << unit << std::endl;
}