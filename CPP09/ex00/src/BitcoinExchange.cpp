/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:19:10 by maroy             #+#    #+#             */
/*   Updated: 2024/08/20 12:03:07 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

namespace {
static std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return str;
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

static bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

static bool isValidDate(const std::string &date) {
    if (date.length() != 10)
        return false;

    for (int i = 0; i < 10; i++) {
        if ((i == 4 || i == 7) && date[i] != '-')
            return false;
        if (i != 4 && i != 7 && !std::isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if (month == 2 && day > (::isLeapYear(year) ? 29 : 28))
        return false;

    return true;
}
}  // namespace

BitcoinExchange::BitcoinExchange() {
    // std::cout << "BitcoinExchange default constructor called" << std::endl;
    this->getPrices();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    // std::cout << "BitcoinExchange copy constructor called" << std::endl;
    this->_btc_prices = other._btc_prices;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
    // std::cout << "BitcoinExchange assignation operator called" << std::endl;
    if (this == &rhs)
        return *this;
    this->_btc_prices = rhs._btc_prices;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    // std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::printPrice(const std::string &date, const double value) const {
    std::map<std::string, double>::const_iterator it = this->_btc_prices.lower_bound(date);
    if (it == this->_btc_prices.end() || it->first != date) {
        if (it == this->_btc_prices.begin())
            throw std::runtime_error("No available exchange rate for the date.");
        --it;
    }

    double exchange_rate = it->second;
    double result = value * exchange_rate;

    std::cout << std::fixed << std::setprecision(2) << date << " | " << value << " BTC = " << result << " USD"
              << " (rate: " << exchange_rate << ")" << std::endl;
}

void BitcoinExchange::processInput(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (file.fail())
        throw std::runtime_error("Error: couldn't open file!");

    std::string line;
    if (!std::getline(file, line) || line != "date | value")
        throw std::runtime_error("Input file header invalid!");

    for (size_t line_nb = 2; std::getline(file, line); ++line_nb) {
        try {
            this->processLine(line);
        } catch (const std::exception &e) {
            std::cerr << "Error on line " << line_nb << ": " << e.what() << std::endl;
        }
    }
}

void BitcoinExchange::processLine(const std::string &line) {
    std::istringstream iss(line);
    std::string date, value_str;

    if (!std::getline(iss, date, '|') || !std::getline(iss, value_str))
        throw std::runtime_error("Bad input format.");

    date = ::trim(date);
    value_str = ::trim(value_str);

    if (!::isValidDate(date))
        throw std::runtime_error("Invalid date.");

    if (value_str.find_first_not_of("0123456789.") != std::string::npos)
        throw std::runtime_error("Invalid characters in value.");
    if (value_str.find('.') != value_str.rfind('.'))
        throw std::runtime_error("Multiple decimal points.");
    if (value_str.find('.') == value_str.size() - 1)
        throw std::runtime_error("Decimal point at end of value.");
    if (value_str.find('.') == 0)
        throw std::runtime_error("Decimal point at start of value.");

    double value = std::strtod(value_str.c_str(), NULL);
    if (value < 0)
        throw std::runtime_error("Negative value.");
    if (value > 1000)
        throw std::runtime_error("Value too large (> 1000).");

    this->printPrice(date, value);
}

void BitcoinExchange::getPrices() {
    std::ifstream file("./data.csv");

    if (!file)
        throw std::runtime_error("Error: Could not open database file.");

    std::string line;
    if (!std::getline(file, line) || line != "date,exchange_rate")
        throw std::runtime_error("Error: Invalid database file header.");

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, rate_str;

        if (!std::getline(iss, date, ',') || !std::getline(iss, rate_str))
            throw std::runtime_error("Error: Invalid database entry format.");

        if (!::isValidDate(date))
            throw std::runtime_error("Error: Invalid date in database: " + date);

        char *end;
        double rate = std::strtod(rate_str.c_str(), &end);
        if (*end != '\0' || rate < 0)
            throw std::runtime_error("Error: Invalid rate in database for date: " + date);

        this->_btc_prices[date] = rate;
    }
    file.close();
}
