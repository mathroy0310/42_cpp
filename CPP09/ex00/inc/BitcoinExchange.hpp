/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:54:11 by mathroy0310       #+#    #+#             */
/*   Updated: 2024/08/19 17:03:51 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
  private:
    std::map<std::string, double> _btc_prices;
    // parsing
    void getPrices();
    void printPrice(const std::string &date, const double value) const;
    void processLine(const std::string &line);
    // cannonical
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &copy);

  public:
    void processInput(const std::string &filename);
    BitcoinExchange();
    ~BitcoinExchange();
};