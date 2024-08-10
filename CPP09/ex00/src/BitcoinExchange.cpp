#include "BitcoinExchange.hpp"

static std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return str;
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

static bool isValidDate(const std::string &date) {
    if (std::strlen(date.c_str()) != 10)
        return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (date[i] != '-')
                return false;
        } else if (!std::isdigit(date[i]))
            return false;
    }

    int year, month, day;
    char delimiter;

    std::istringstream date_stream(date);
    date_stream >> year >> delimiter >> month >> delimiter >> day;
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    bool is_leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    if (month == 2 && day > (is_leap ? 29 : 28))
        return false;
    return true;
}

void BitcoinExchange::printPrice(const std::string &date, const float value, size_t line_nb) {
    if (!isValidDate(date)) {
        std::cerr << "Error: invalid date at line: " << line_nb << std::endl;
        return;
    }
    std::map<std::string, float>::iterator it = _btc_prices.lower_bound(date);
    if (it == _btc_prices.end() || it->first != date) {
        if (it == _btc_prices.begin()) {
            std::cerr << "Error: no available exchange rate for the date " << date << std::endl;
            return;
        }
        --it;
    }
    const std::string &closest_date = it->first;
    float exchange_rate = it->second;

    float result = value * exchange_rate;
    std::cout << closest_date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::processInput(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (file.fail())
        throw std::runtime_error("Error: couldn't open file!");

    std::string line;
    std::getline(file, line);
    if (line != "date | value")
        throw std::runtime_error("Input file header invalid!");
    size_t line_nb = 2;
    while (std::getline(file, line)) {
        std::stringstream err_ss;
        std::istringstream iss(line);
        std::string date, value_str;

        if (!std::getline(iss, date, '|') || !std::getline(iss, value_str)) {
            std::cerr << "Error: bad input at line: " << line_nb++ << std::endl;
            continue;
        }

        date = trim(date);
        value_str = trim(value_str);
        try {
            if (value_str.find_first_not_of("0123456789.") != std::string::npos) {
                err_ss << "Error: invalid value at line: " << line_nb;
                throw std::out_of_range(err_ss.str());
            }

            char *end;
            float value = std::strtof(value_str.c_str(), &end);
            if (value < 0) {
                err_ss << "Error: negative value at line: " << line_nb;
                throw std::out_of_range(err_ss.str());
            } else if (value > 1000) {
                err_ss << "Error: too large a number at line: " << line_nb;
                throw std::out_of_range(err_ss.str());
            }
            printPrice(date, value, line_nb);
        } catch (const std::out_of_range &e) {
            std::cerr << e.what() << std::endl;
        }
        line_nb++;
    }
    file.close();
}

void BitcoinExchange::getPrices() {
    std::ifstream file("./data.csv");

    if (file.fail())
        throw std::runtime_error("Error: couldn't open database!");
    std::string line;
    std::getline(file, line);
    if (line != "date,exchange_rate") {
        file.close();
        throw std::runtime_error("Error: Database header invalid!");
    }
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, value_str;
        if (!std::getline(iss, date, ',') || !std::getline(iss, value_str)) {
            file.close();
            throw std::runtime_error("Error: not enough cells in database");
        }
        try {
            char *end;
            float value = std::strtof(value_str.c_str(), &end);
            _btc_prices[date] = value;
        } catch (const std::invalid_argument &e) {
            std::cerr << "Error: invalid value '" << value_str << "' for date " << date << std::endl;
        } catch (const std::out_of_range &e) {
            std::cerr << "Error: value out of range '" << value_str << "' for date " << date << std::endl;
        }
    }
    file.close();
}

BitcoinExchange::BitcoinExchange() {
    getPrices();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    _btc_prices = other._btc_prices;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
    if (this == &copy)
        return *this;
    _btc_prices = copy._btc_prices;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}