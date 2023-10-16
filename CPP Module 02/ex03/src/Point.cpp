/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Point.cpp                                         ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/16 15:39:56 by maroy                                    */
/*   Updated: 2023/10/16 16:15:23 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"


///////////////////////////////////////////////////////////
///														///
///			CONSTRUCTORS AND DESTRUCTORS				///
///														///
///////////////////////////////////////////////////////////

Point::Point() : _x(0), _y(0){
	//cout << ANSI_COLOR_GREEN << "Default constructor called" << ANSI_COLOR_RESET << endl;
}

Point::Point(Fixed const x, const Fixed y) : _x(x), _y(y){
	//cout << ANSI_COLOR_GREEN << "Constructor called" << ANSI_COLOR_RESET << endl;
}

Point::~Point(){
	//cout << ANSI_COLOR_GREEN << "Destructor called" << ANSI_COLOR_RESET << endl;
}

////////////////////////////////////////////////////////////
///														///
///			OPERATION OVERLOAD							///
///														///
///////////////////////////////////////////////////////////

Point &Point::operator=(Point const &rhs) {
    // Assign x and y using non-const member functions
    this->setX(rhs.getX());
    this->setY(rhs.getY());
    return (*this);
}

///////////////////////////////////////////////////////////
///														///
///			GETTERS										///
///														///
///////////////////////////////////////////////////////////

Fixed	Point::getX( void ) const {
	return(this->_x);
}

Fixed	Point::getY( void ) const {
	return (this->_y);
}

///////////////////////////////////////////////////////////
///														///
///			SETTERS										///
///														///
///////////////////////////////////////////////////////////

void	Point::setX(Fixed const x ){
	(void)x;
}

void	Point::setY(Fixed const y ){
	(void)y;
}