/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:36:52 by maroy             #+#    #+#             */
/*   Updated: 2024/08/20 13:43:04 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <stack>


class RPN {

  public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &copy);
    ~RPN();
    RPN(const std::string &arg);

    private:
        std::stack<int> _stack;      
        
         
};