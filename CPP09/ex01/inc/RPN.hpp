/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:36:52 by maroy             #+#    #+#             */
/*   Updated: 2024/08/20 23:08:08 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ostream>
#include <stack>
#include <string>

class RPN {

  public:
    RPN(const std::string &arg);
    ~RPN();
    void handleDigit(const std::string &arg, size_t &i);
    void handleOperator(char op);

  private:
    RPN();                            // dont want to compile
    RPN(const RPN &other);            // dont want to compile
    RPN &operator=(const RPN &copy);  // dont want to compile

    std::stack<int> _stack;
};