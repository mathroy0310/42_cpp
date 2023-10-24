/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Dog.cpp                                           ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:49:40 by maroy                                    */
/*   Updated: 2023/10/24 15:40:04 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Dog.hpp"

///////////////////////////////////
///	CONSTRUCTORS & DESTRUCTOR	///
///////////////////////////////////

Dog::Dog(){
	setType("Dog");
	this->_brain = new Brain();
}

Dog::Dog(Dog const & src) {
	cout << "Dog copy constructor" << endl;
	*this = src;
}

Dog::~Dog() {
    cout << "Dog destructor" << endl;
	delete this->_brain;
}

///////////////////////////
///		OPERATORS		///
///////////////////////////

Dog & Dog::operator=(Dog const & src) {
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

///////////////////////////////
///		MEMBER FONCTIONS	///
///////////////////////////////

void Dog::makeSound() const {
    cout << "Woof! I'm a Dog." << endl;
}