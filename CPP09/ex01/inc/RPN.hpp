/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:36:52 by maroy             #+#    #+#             */
/*   Updated: 2024/08/27 22:54:20 by maroy            ###   ########.fr       */
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
    void handleDigit(char digit);
    void handleOperator(char op);

  private:
    RPN();                            // dont want to compile
    RPN(const RPN &other);            // dont want to compile
    RPN &operator=(const RPN &copy);  // dont want to compile

    std::stack<int> _stack;
};