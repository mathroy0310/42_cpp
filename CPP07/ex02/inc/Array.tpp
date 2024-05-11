/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:35:07 by maroy             #+#    #+#             */
/*   Updated: 2024/05/10 14:11:33 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T> Array<T>::Array() : _arr_size(0) {
    this->_arr = NULL;
    std::cout << "Array constructor called" << std::endl;
}

template <typename T> Array<T>::~Array() {
    if (this->_arr)
        delete[] this->_arr;
    std::cout << "Array destructor called" << std::endl;
}

template <typename T> Array<T>::Array(unsigned int n) : _arr_size(n) {
    this->_arr = new T[this->_arr_size];
    std::cout << "Initialized array with " << this->size() << " elements." << std::endl;
}

template <typename T> Array<T>::Array(const Array &src) : _arr_size(src.size()) {
    this->_arr = NULL;
    *this = src;
    std::cout << "Array copy constructor called" << std::endl;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &rhs) {
    if (this->_arr)
        delete[] this->_arr;
    if (this != &rhs && rhs.size() > 0) {
        this->_arr_size = rhs.size();
        this->_arr = new T[this->_arr_size];
        for (unsigned int x = 0; x < this->size(); x++) {
            this->_arr[x] = rhs._arr[x];
        }
    }
    std::cout << "Array copy assignment operator called" << std::endl;
    return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int index) {
    if (this->_arr == NULL || index >= this->size()) {
        std::cout << "index: " << index << std::endl;
        throw IndexOutOfBoundsException();
    }
    return this->_arr[index];
}

template <typename T> unsigned int Array<T>::size() const {
    return this->_arr_size;
}

template <typename T> const char *Array<T>::IndexOutOfBoundsException::what() const throw() {
    return ("Error: Index out of bounds");
}