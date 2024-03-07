/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:59:14 by maroy             #+#    #+#             */
/*   Updated: 2024/03/06 23:18:28 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter() {
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string input) : _input(input) {
    std::cout << "Parametric constructor called" << std::endl;
    this->_double = atof(this->getInput().c_str());
    this->convertInput();
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) : _input(src.getInput()) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
    if (this != &rhs)
        *this = rhs;
    this->_type = rhs.getType();
    this->_char = rhs.getChar();
    this->_int = rhs.getInt();
    this->_float = rhs.getFloat();
    this->_double = rhs.getDouble();
    return *this;
}

/*
** --------------------------------- MEMBER FUNCTIONS --------------------------
*/

int ScalarConverter::findType(void) {
    if (this->getInput().compare("nan") == 0 || this->getInput().compare("+inf") == 0 ||
        this->getInput().compare("-inf") == 0)
        return (NAN_INF);
    else if (this->getInput().length() == 1 && (this->getInput()[0] == '+' || this->getInput()[0] == '-' ||
                                                this->getInput()[0] == 'f' || this->getInput()[0] == '.'))
        return (CHAR);
    else if (this->getInput().find_first_of("+-") != this->getInput().find_last_of("+-"))
        return (ERROR);
    else if (this->getInput().find_first_not_of("+-0123456789") == std::string::npos)
        return (INT);
    else if ((this->getInput().length() == 1 && std::isprint(this->getInput()[0])) ||
             (this->getInput().length() == 1 && std::isalpha(this->getInput()[0])))
        return (CHAR);
    else
        return (ERROR);
}

void ScalarConverter::fromChar(void) {
    this->_char = static_cast<unsigned char>(this->getInput()[0]);
    this->_int = static_cast<int>(this->getChar());
    this->_float = static_cast<float>(this->getChar());
    this->_double = static_cast<double>(this->getChar());
}
void ScalarConverter::fromInt(void) {
    this->_int = static_cast<int>(this->getDouble());
    this->_char = static_cast<unsigned char>(this->getInt());
    this->_float = static_cast<float>(this->getDouble());
}
void ScalarConverter::fromFloat(void) {
    this->_float = static_cast<float>(this->getDouble());
    this->_char = static_cast<char>(this->getFloat());
    this->_int = static_cast<int>(this->getFloat());
}
void ScalarConverter::fromDouble(void) {
    this->_char = static_cast<char>(this->getDouble());
    this->_int = static_cast<int>(this->getDouble());
    this->_float = static_cast<float>(this->getDouble());
}

void ScalarConverter::printChar(void) const {
    std::cout << "char: ";
    if (this->getType() != NAN_INF && this->getDouble() <= 255 && this->getDouble() >= 0) {
        if (isprint(this->getChar()))
            std::cout << "'" << this->getChar() << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    } else
        std::cout << COLOR_RED << "impossible" << COLOR_CYAN << std::endl;
}

void ScalarConverter::printInt(void) const {
    std::cout << "int: ";
    if (this->getType() != NAN_INF && this->getDouble() >= std::numeric_limits<int>::min() &&
        this->getDouble() <= std::numeric_limits<int>::max()) {

        std::cout << this->getInt() << std::endl;
    } else
        std::cout << COLOR_RED << "impossible" << COLOR_CYAN << std::endl;
}

void ScalarConverter::printFloat(void) const {
    std::cout << "float: ";
    if (this->getType() != NAN_INF && this->getDouble() >= -std::numeric_limits<float>::max() &&
        this->getDouble() <= std::numeric_limits<float>::max()) {
        std::cout << this->getFloat();
        if (this->getFloat() - this->getInt() == 0)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    } else
        this->printNanInf();
}

void ScalarConverter::printDouble(void) const {
    std::cout << "double: ";
    if (this->getType() != NAN_INF) {
        std::cout << this->getDouble();
        if (this->getDouble() - this->getInt() == 0)
            std::cout << ".0";
        std::cout << std::endl;
    } else
        this->printNanInf();
}

void ScalarConverter::printNanInf(void) const {
    if (this->getInput() == "nan" || this->getInput() == "nanf")
        std::cout << "nan" << std::endl;
    else if (this->getInput()[0] == '+')
        std::cout << "+inf" << std::endl;
    else
        std::cout << "-inf" << std::endl;
}

void ScalarConverter::convertInput(void) {
    void (ScalarConverter::*converters[])(void) = {&ScalarConverter::fromChar, &ScalarConverter::fromInt,
                                                   &ScalarConverter::fromFloat, &ScalarConverter::fromDouble};
    int types[] = {CHAR, INT, FLOAT, DOUBLE};

    this->_type = this->findType();
    if (this->getType() == NAN_INF)
        return;

    int i = 0;
    for (; i < 4; i++) {
        if (this->getType() == types[i]) {
            (this->*converters[i])();
            break;
        }
    }
    if (i == 4)
        throw ScalarConverter::ImpossibleConversionException();
}

void ScalarConverter::printOutput(void) const {
    std::cout << COLOR_CYAN;
    this->printChar();
    this->printInt();
    this->printFloat();
    this->printDouble();
    std::cout << COLOR_RESET;
}

/*
** --------------------------------- GETTERS ----------------------------------
*/

std::string ScalarConverter::getInput(void) const {
    return this->_input;
}

int ScalarConverter::getType(void) const {
    return this->_type;
}

char ScalarConverter::getChar(void) const {
    return this->_char;
}

int ScalarConverter::getInt(void) const {
    return this->_int;
}

float ScalarConverter::getFloat(void) const {
    return this->_float;
}

double ScalarConverter::getDouble(void) const {
    return this->_double;
}
/*
** ------------------------------- EXCEPTION ----------------------------------
*/
const char *ScalarConverter::ImpossibleConversionException::what(void) const throw() {
    return (COLOR_RED "Error: Impossible not convertable" COLOR_RESET);
};

/* ************************************************************************** */