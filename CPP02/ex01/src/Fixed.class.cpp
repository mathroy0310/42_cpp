/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Fixed.class.cpp                                   ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 20:52:47 by maroy                                    */
/*   Updated: 2023/11/05 16:15:05 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Fixed.class.hpp"
#include "common.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void)
	: _rawBits(0)
{
	cout << ANSI_COLOR_CYAN << "Default constructor called" << ANSI_COLOR_RESET << endl;
}

Fixed::Fixed(int const n)
{
	cout << ANSI_COLOR_CYAN << "Int constructor called" << ANSI_COLOR_RESET << endl;
	this->_rawBits = n << this->_fractionalBits;
}

Fixed::Fixed(float const n)
{
	cout << ANSI_COLOR_CYAN << "Float constructor called" << ANSI_COLOR_RESET << endl;
	this->_rawBits = roundf(n * (1 << this->_fractionalBits));
}

Fixed::Fixed(Fixed const &src)
{
	cout << ANSI_COLOR_CYAN << "Copy constructor called" << ANSI_COLOR_RESET << endl;
	*this = src;
}

Fixed::~Fixed()
{
	cout << ANSI_COLOR_CYAN << "Destructor called" << ANSI_COLOR_RESET << endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	cout << ANSI_COLOR_CYAN << "Copy assignation operator called" << ANSI_COLOR_RESET << endl;
	this->_rawBits = rhs.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
int Fixed::getRawBits(void) const
{
	//cout << ANSI_COLOR_CYAN << "getRawBits member function called" << ANSI_COLOR_RESET << endl;
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	//cout << ANSI_COLOR_CYAN << "setRawBits member function called" << ANSI_COLOR_RESET << endl;
	this->_rawBits = raw;
}

void Fixed::printRawBits(void) const
{
	cout << ANSI_COLOR_BLUE << "RawBits value is: " << ANSI_COLOR_RESET << this->_rawBits << endl;
}

int Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_fractionalBits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << this->_fractionalBits));
}
