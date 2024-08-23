/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 03:15:59 by maroy             #+#    #+#             */
/*   Updated: 2024/08/23 14:29:03 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename Container> void PmergeMe::merge(Container &cont, int first, int mid, int second) {
    int size1 = mid - first + 1;
    int size2 = second - mid;

    typename Container::iterator first_begin = cont.begin() + first;
    typename Container::iterator mid_begin = cont.begin() + mid + 1;

    Container first_arr(first_begin, first_begin + size1);
    Container second_arr(mid_begin, mid_begin + size2);

    typename Container::iterator it1 = first_arr.begin();
    typename Container::iterator it2 = second_arr.begin();
    typename Container::iterator it_cont = cont.begin() + first;
    while (it1 != first_arr.end() && it2 != second_arr.end()) {
        if (*it1 <= *it2) {
            *it_cont = *it1;
            ++it1;
        } else {
            *it_cont = *it2;
            ++it2;
        }
        ++it_cont;
    }

    while (it1 != first_arr.end()) {
        *it_cont = *it1;
        ++it1;
        ++it_cont;
    }

    while (it2 != second_arr.end()) {
        *it_cont = *it2;
        ++it2;
        ++it_cont;
    }
}

template <typename Container> void PmergeMe::mergeInsertionSort(Container &cont, int first, int second) {
    if (first < second) {
        if (second - first <= 16)  // deux fois plus rapide
            insertionSort(cont, first, second);
        else {
            int mid = first + (second - first) / 2;
            mergeInsertionSort(cont, first, mid);
            mergeInsertionSort(cont, mid + 1, second);
            merge(cont, first, mid, second);
        }
    }
}

template <typename Container> void PmergeMe::insertionSort(Container &cont, int first, int last) {
    for (int i = first + 1; i <= last; i++) {
        int curr = cont[i];
        int j = i - 1;
        while (j >= first && cont[j] > curr) {
            cont[j + 1] = cont[j];
            j--;
        }
        cont[j + 1] = curr;
    }
}

template <typename Container> void PmergeMe::algoContainer(Container &cont, double &time) {
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    mergeInsertionSort(cont, 0, cont.size() - 1);
    gettimeofday(&end, 0);
    long sec = end.tv_sec - begin.tv_sec;
    long msec = end.tv_usec - begin.tv_usec;
    double timer = sec * 1e6 + msec;
    time = this->_time_input + timer;
}

template <typename Container> void PmergeMe::printContainer(Container &cont) {
    for (typename Container::iterator it = cont.begin(); it != cont.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container> void PmergeMe::printInfo(Container &cont, std::string type, double time) {
    std::cout << "Time to process a range of " << cont.size() << " elements with " << type << " : ";
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << time << " us (" << time / 1e6 << " s)" << std::endl;
}
