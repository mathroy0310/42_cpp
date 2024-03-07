/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:59:16 by maroy             #+#    #+#             */
/*   Updated: 2024/03/06 23:18:41 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

#define NAN_INF 1
#define ERROR 2
#define CHAR 3
#define INT 4
#define FLOAT 5
#define DOUBLE 6

#define COLOR_RESET "\x1b[0m"
#define COLOR_RED "\x1b[31m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_BOLD "\x1b[1;37m"

class ScalarConverter {

  private:
    const std::string _input;
    int _type;
    char _char;
    int _int;
    float _float;
    double _double;

    ScalarConverter();

    void convertInput(void);

    void fromChar(void);
    void fromInt(void);
    void fromFloat(void);
    void fromDouble(void);

    int findType(void);

    void printChar(void) const;
    void printInt(void) const;
    void printFloat(void) const;
    void printDouble(void) const;
    void printNanInf(void) const;

    std::string getInput(void) const;
    int getType(void) const;
    char getChar(void) const;
    int getInt(void) const;
    float getFloat(void) const;
    double getDouble(void) const;

  public:
    ScalarConverter(std::string input);
    ScalarConverter(ScalarConverter const &src);
    ~ScalarConverter();

    void printOutput(void) const;
    ScalarConverter &operator=(ScalarConverter const &rhs);

    class ImpossibleConversionException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

#endif /* ************************************************* SCALARCONVERTER_H */