/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   WrongAnimal.cpp                                   ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 19:29:39 by maroy                                    */
/*   Updated: 2023/10/20 19:32:00 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	cout << "WrongAnimal default constructor called" << endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src){
	cout << "WrongAnimal copy constructor called" << endl;
	*this = src;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & src){
	this->_type = src.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	cout << "WrongAnimal destructor called" << endl;
}

void WrongAnimal::makeSound() const{
	cout << "WrongAnimal makeSound called" << endl;
}

string	WrongAnimal::getType() const{
	return (this->_type);
}
