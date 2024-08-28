/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 03:15:59 by maroy             #+#    #+#             */
/*   Updated: 2024/08/27 22:47:20 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <utility>

template <typename Container> void PmergeMe::sort(Container &cont, double &time) {
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    std::vector<std::pair<int, int>> pairs;
    Container s;  // bigger nums of each pair + last if uneven
    Container jacobsthal;

    createPairs(cont, pairs, s);
    std::sort(s.begin(), s.end());
    // this->printContainer(s);
    generateJacobsthalSequence(s, jacobsthal);
    insertSort(pairs, s, jacobsthal);

    cont = s;

    gettimeofday(&end, 0);
    time = _time_input + calculateTime(begin, end);
}

template <typename Container>
void PmergeMe::createPairs(const Container &cont, std::vector<std::pair<int, int>> &pairs, Container &s) {
    for (size_t i = 0; i < cont.size(); i += 2) {
        if (i + 1 < cont.size()) {
            std::pair<int, int> p = std::make_pair(cont[i], cont[i + 1]);
            if (p.first < p.second)
                std::swap(p.first, p.second);  // sort the pair
            pairs.push_back(p);
            s.push_back(p.first);  // append the bigger
        } else
            s.push_back(cont.back());
    }
}

template <typename Container> void PmergeMe::generateJacobsthalSequence(const Container &s, Container &jacobsthal) {
    // 0, 1, 3, 15, 55, 231, 903, 3655, 14535, 58311,  ... J(n) = J(n-1) + 2 * J(n-2) for n > 1
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (jacobsthal.back() < static_cast<int>(s.size()))
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
}

template <typename Container>
typename Container::iterator PmergeMe::binarySearch(Container &s, int value, typename Container::iterator begin,
                                                    typename Container::iterator end) {
    (void)s;
    while (begin < end) {
        typename Container::iterator mid = begin + (end - begin) / 2;

        if (value < *mid)
            end = mid;
        else
            begin = mid + 1;
    }
    return begin;
}

template <typename Container>
void PmergeMe::insertSort(std::vector<std::pair<int, int>> &pairs, Container &s, const Container &jacobsthal) {
    for (size_t i = 0; i < pairs.size(); i++) {
        for (size_t j = 0; j < jacobsthal.size(); j++) {
            int k = jacobsthal[j];
            if (k >= static_cast<int>(s.size()))
                k = s.size() - 1;
            if (pairs[i].second < s[k]) {
                // Use binary search to find the insertion point
                typename Container::iterator insertPos = binarySearch(s, pairs[i].second, s.begin(), s.begin() + k + 1);
                s.insert(insertPos, pairs[i].second);
                break;
            }
            if (j == jacobsthal.size() - 1 || k == static_cast<int>(s.size()) - 1) {
                if (pairs[i].second > s.back()) {
                    s.push_back(pairs[i].second);
                } else {
                    // Use binary search to find the insertion point in the entire container
                    typename Container::iterator insertPos = binarySearch(s, pairs[i].second, s.begin(), s.end());
                    s.insert(insertPos, pairs[i].second);
                }
                break;
            }
        }
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
    std::cout << time << " us" << std::endl;
}