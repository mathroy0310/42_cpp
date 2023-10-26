/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Fixed.cpp                                         ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 20:52:47 by maroy                                    */
/*   Updated: 2023/10/16 12:29:04 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"
#include "../inc/Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0){
	cout << ANSI_COLOR_CYAN << "Default constructor called" << ANSI_COLOR_RESET << endl;
}

Fixed::Fixed( Fixed const & src ){
	cout << ANSI_COLOR_CYAN << "Copy constructor called" << ANSI_COLOR_RESET << endl;
	*this = src;
}

Fixed::~Fixed(){
	cout << ANSI_COLOR_CYAN << "Destructor called" << ANSI_COLOR_RESET << endl;
}

Fixed& Fixed::operator=( Fixed const & rhs){
	cout << ANSI_COLOR_CYAN << "Copy assignation operator called" << ANSI_COLOR_RESET << endl;
	this->_rawBits = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const{
	cout << ANSI_COLOR_CYAN << "getRawBits member function called" << ANSI_COLOR_RESET << endl;
	return (this->_rawBits);
}

void Fixed::setRawBits( int const raw ){
	cout << ANSI_COLOR_CYAN << "setRawBits member function called" << ANSI_COLOR_RESET << endl;
	this->_rawBits = raw;
}