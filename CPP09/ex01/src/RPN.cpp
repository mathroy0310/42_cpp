/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:48:21 by maroy             #+#    #+#             */
/*   Updated: 2024/08/20 14:23:28 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

namespace {
    bool isOP(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
}

RPN::RPN() {
    // std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const std::string &arg) {
    // std::cout << "RPN parametric constructor called" << std::endl;
    
    size_t i = 0;
    while(i < arg.length())
    {
        while (isspace(arg[i]))
        {
            i++;
            if (i == arg.length())
                break;
        }
        if (isdigit(arg[i]))
        {
            if (isdigit(arg[i + 1]))
            {
                throw std::invalid_argument("Invalid expression: only 0-9");
            }
            _stack.push(arg[i] - '0');
        }
        else if (isOP(arg[i]))
        {
            if (_stack.size() < 2)
            {
                throw std::invalid_argument("Invalid expression: not enough operands");
            }
            if (_stack.top() == 0 && arg[i] == '/')
            {
                throw std::invalid_argument("Invalid expression: division by zero");
            }

            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();

            if (arg[i] == '+')
                _stack.push(b + a);
            else if (arg[i] == '-')
                _stack.push(b - a);
            else if (arg[i] == '*')
                _stack.push(b * a);
            else if (arg[i] == '/')
                _stack.push(b / a);
        }
        else
        {
            throw std::invalid_argument("Invalid expression: invalid character {" + std::to_string(arg[i]) + "}");
        }
        i++;
    }
    std::cout << _stack.top() << std::endl;
    
}

RPN::RPN(const RPN &other) {
    // std::cout << "RPN copy constructor called" << std::endl;
    *this = other;
}

RPN &RPN::operator=(const RPN &rhs) {
    // std::cout << "RPN assignation operator called" << std::endl;
    if (this == &rhs)
        return *this;
    this->_stack = rhs._stack;
    return *this;
}

RPN::~RPN() {
    // std::cout << "RPN destructor called" << std::endl;
}