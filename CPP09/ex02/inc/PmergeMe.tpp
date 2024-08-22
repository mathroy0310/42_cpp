/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 03:15:59 by maroy             #+#    #+#             */
/*   Updated: 2024/08/22 04:08:42 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename Container>
void PmergeMe::merge(Container& cont, int first, int mid, int second) {
    int size1 = mid - first + 1;
    int size2 = second - mid;
    Container first_arr(size1);
    Container second_arr(size2);

    for (int i = 0; i < size1; i++)
        first_arr[i] = cont[first + i];
    
    for (int j = 0; j < size2; j++)
        second_arr[j] = cont[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = first;

    while (i < size1 && j < size2) {
        if (first_arr[i] <= second_arr[j]) {
            cont[k] = first_arr[i];
            i++;
        } else {
            cont[k] = second_arr[j];
            j++;
        }
        k++;
    }
    while (i < size1) {
        cont[k] = first_arr[i];
        i++;
        k++;
    }
    while (j < size2) {
        cont[k] = second_arr[j];
        j++;
        k++;
    }
}

template <typename Container>
void PmergeMe::mergeInsertionSort(Container& cont, int first, int second) {
    if (first < second) {
        if (second - first <= 16) // deux fois plus rapide
            insertionSort(cont, first, second);
        else {
            int mid = first + (second - first) / 2;
            mergeInsertionSort(cont, first, mid);
            mergeInsertionSort(cont, mid + 1, second);
            merge(cont, first, mid, second);
        }
    }
}

template <typename Container>
void PmergeMe::insertionSort(Container& cont, int first, int last) {
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

template <typename Container>
void PmergeMe::algoContainer(Container& cont, double& time) {
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    mergeInsertionSort(cont, 0, cont.size() - 1);
    gettimeofday(&end, 0);
    long sec = end.tv_sec - begin.tv_sec;
    long msec = end.tv_usec - begin.tv_usec;
    double timer = sec * 1e6 + msec;
    time = time_input + timer;
}
