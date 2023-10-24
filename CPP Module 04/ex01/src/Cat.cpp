/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Cat.cpp                                           ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:48:37 by maroy                                    */
/*   Updated: 2023/10/24 15:40:06 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Cat.hpp"

///////////////////////////////////
///	CONSTRUCTORS & DESTRUCTOR	///
///////////////////////////////////

Cat::Cat() {
	setType("Cat");
	this->_brain = new Brain();
}

Cat::Cat(Cat const & src) {
	cout << "Cat copy constructor" << endl;
	*this = src;
}

Cat::~Cat() {
    cout << "Cat destructor" << endl;
	delete this->_=brain;
}

///////////////////////////
///		OPERATORS		///
///////////////////////////

Cat &Cat::operator=(Cat const & src) {
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

///////////////////////////////
///		MEMBER FONCTIONS	///
///////////////////////////////

void Cat::makeSound() const {
    cout << "Meow! I'm a cat." << endl;
}