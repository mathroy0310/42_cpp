/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:35:13 by maroy             #+#    #+#             */
/*   Updated: 2024/07/30 13:22:28 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
    std::cout << "default Constructor Called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src) {
    std::cout << "Copy Constructor Called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << "default Deconstructor Called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src) {
     if (this != &src) {
        std::stack<T>::operator=(src); 
    }
    return *this;
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
    return std::stack<T>::c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
    return std::stack<T>::c.end();
}

template <typename T>
void MutantStack<T>::push(const T &val) {
    std::cout << "pushed: " << val << std::endl;
    std::stack<T>::push(val);
}

template <typename T>
void MutantStack<T>::pop(){
    if (this->empty())
        throw EmptyStack();
    std::cout << "popped: " << std::stack<T>::top() << std::endl;
    std::stack<T>::pop();
}