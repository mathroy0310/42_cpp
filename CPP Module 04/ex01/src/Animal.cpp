/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Animal.cpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:41:14 by maroy                                    */
/*   Updated: 2023/10/24 15:06:47 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	//cout << "Animal default constructor called" << endl;
}

Animal::Animal(Animal const & src){
	//cout << "Animal copy constructor called" << endl;
	*this = src;
}

Animal::~Animal(){
	//cout << "Animal destructor called" << endl;
}

///////////////////////////
///		OPERATORS		///
///////////////////////////

Animal & Animal::operator=(Animal const & src){
	this->_type = src.getType();
	return (*this);
}

///////////////////////////////
///		MEMBER FONCTIONS	///
///////////////////////////////

void	Animal::makeSound() const{
	cout << "Animal sound ..." << endl;
}

///////////////////////////////
///		Setters & Getters	///
///////////////////////////////

string	Animal::getType() const{
	return (this->_type);
}

void	Animal::setType(string type){
	this->_type = type;
}
