/* ************************************************************************** */
/*                                                             _              */
/*                                                 __   ___.--'_\`.           */
/*   BitcoinExchange.hpp                          ( _\`.' -   'o\` )          */
/*                                                _\\.'_'      _.-'           */
/*   By: mathroy0310 <maroy0310@gmail.com>       ( \`. )    //\\\`            */
/*                                                \\_'-`---'\\__,             */
/*   Created: 2024/08/10 15:54:11 by mathroy0310   \`        `-\\             */
/*   Updated: 2024/08/10 17:57:49 by mathroy0310    `                         */
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
    std::map<std::string, float> _btc_prices;
    // parsing
    void getPrices();
    void printPrice(const std::string &date, const float value, size_t line_nb);
    // cannonical
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &copy);

  public:
    void processInput(const std::string &filename);
    BitcoinExchange();
    ~BitcoinExchange();
};