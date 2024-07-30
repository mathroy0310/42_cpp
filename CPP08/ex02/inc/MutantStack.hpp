/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:21:44 by maroy             #+#    #+#             */
/*   Updated: 2024/07/30 13:22:37 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

class EmptyStack : public std::exception {
  public:
    virtual const char *what() const throw() { return ("\x1b[31;1mERROR: Pop from empty stack\x1b[0m"); };
};

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack();
    MutantStack(const MutantStack &src);
    virtual ~MutantStack();

    MutantStack &operator=(const MutantStack &src);

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin();
    iterator end();

    void pop();
    void push(const T &val);
};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP
