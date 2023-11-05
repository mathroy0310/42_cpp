/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Fixed.class.cpp                                   ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 20:52:47 by maroy                                    */
/*   Updated: 2023/11/05 16:26:12 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "common.hpp"

const int Fixed::_fractionalBits = 8;

///////////////////////////////////////////////////////////
///														///
///			CONSTRUCTORS AND DESTRUCTORS				///
///														///
///////////////////////////////////////////////////////////

Fixed::Fixed(void)
	: _rawBits(0)
{
	//cout << ANSI_COLOR_CYAN << "Default constructor called" << ANSI_COLOR_RESET << endl;
}

Fixed::Fixed(int const n)
{
	//cout << ANSI_COLOR_CYAN << "Int constructor called" << ANSI_COLOR_RESET << endl;
	this->_rawBits = n << this->_fractionalBits;
}

Fixed::Fixed(float const n)
{
	//cout << ANSI_COLOR_CYAN << "Float constructor called" << ANSI_COLOR_RESET << endl;
	this->_rawBits = roundf(n * (1 << this->_fractionalBits));
}

Fixed::Fixed(Fixed const &src)
{
	//cout << ANSI_COLOR_CYAN << "Copy constructor called" << ANSI_COLOR_RESET << endl;
	*this = src;
}

Fixed::~Fixed()
{
	//cout << ANSI_COLOR_CYAN << "Destructor called" << ANSI_COLOR_RESET << endl;
}

////////////////////////////////////////////////////////////
///														///
///			OPERATION OVERLOAD							///
///														///
///////////////////////////////////////////////////////////

Fixed &Fixed::operator=(Fixed const &rhs)
{
	//cout << ANSI_COLOR_CYAN << "Copy assignation operator called" << ANSI_COLOR_RESET << endl;
	this->_rawBits = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator<(Fixed const &rhs) const
{
	//cout << ANSI_COLOR_CYAN << "Less than operator called" << ANSI_COLOR_RESET << endl;
	return (this->_rawBits < rhs.getRawBits());
}

bool Fixed::operator>(Fixed const &rhs) const
{
	//cout << ANSI_COLOR_CYAN << "Greater than operator called" << ANSI_COLOR_RESET << endl;
	return (this->_rawBits > rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	//cout << ANSI_COLOR_CYAN << "Less than or equal operator called" << ANSI_COLOR_RESET << endl;
	return (this->_rawBits <= rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	//cout << ANSI_COLOR_CYAN << "Greater than or equal operator called" << ANSI_COLOR_RESET << endl;
	return (this->_rawBits >= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs) const
{
	//cout << ANSI_COLOR_CYAN << "Equal operator called" << ANSI_COLOR_RESET << endl;
	return (this->_rawBits == rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	//cout << ANSI_COLOR_CYAN << "Addition operator called" << ANSI_COLOR_RESET << endl;
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	//cout << ANSI_COLOR_CYAN << "Substraction operator called" << ANSI_COLOR_RESET << endl;
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	//cout << ANSI_COLOR_CYAN << "Multiplication operator called" << ANSI_COLOR_RESET << endl;
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	if (rhs.toFloat() == 0)
	{
		throw std::invalid_argument("Division by zero");
	}
	//cout << ANSI_COLOR_CYAN << "Division operator called" << ANSI_COLOR_RESET << endl;
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	//cout << ANSI_COLOR_CYAN << "Increment operator called" << ANSI_COLOR_RESET << endl;
	this->_rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	//cout << ANSI_COLOR_CYAN << "Increment operator called" << ANSI_COLOR_RESET << endl;
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	//cout << ANSI_COLOR_CYAN << "Decrement operator called" << ANSI_COLOR_RESET << endl;
	this->_rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	//cout << ANSI_COLOR_CYAN << "Decrement operator called" << ANSI_COLOR_RESET << endl;
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

ostream &operator<<(ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

///////////////////////////////////////////////////////////
///														///
///			GETTERS										///
///														///
///////////////////////////////////////////////////////////

int Fixed::getRawBits(void) const
{
	//cout << ANSI_COLOR_CYAN << "getRawBits member function called" << ANSI_COLOR_RESET << endl;
	return (this->_rawBits);
}

///////////////////////////////////////////////////////////
///														///
///			SETTERS										///
///														///
///////////////////////////////////////////////////////////

void Fixed::setRawBits(int const raw)
{
	//cout << ANSI_COLOR_CYAN << "setRawBits member function called" << ANSI_COLOR_RESET << endl;
	this->_rawBits = raw;
}

///////////////////////////////////////////////////////////
///														///
///			OTHERS										///
///														///
///////////////////////////////////////////////////////////

void Fixed::printRawBits(void) const
{
	cout << ANSI_COLOR_YELLOW << "RawBits value is: " << ANSI_COLOR_RESET << this->_rawBits << endl;
}

void Fixed::printBits(string name) const
{
	cout << ANSI_COLOR_YELLOW << name << " Bits value is: " << ANSI_COLOR_RESET << this->toFloat() << endl;
}

int Fixed::toInt(void) const
{
	//cout << ANSI_COLOR_CYAN << "toInt member function called" << ANSI_COLOR_RESET << endl;
	return (this->_rawBits >> this->_fractionalBits);
}

float Fixed::toFloat(void) const
{
	//cout << ANSI_COLOR_CYAN <<
	return ((float)this->_rawBits / (float)(1 << this->_fractionalBits));
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}