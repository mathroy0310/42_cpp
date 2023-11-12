/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Cat.class.cpp                                     ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:48:37 by maroy                                    */
/*   Updated: 2023/11/11 16:34:37 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Cat.class.hpp"

///////////////////////////////////
///	CONSTRUCTORS & DESTRUCTOR	///
///////////////////////////////////

Cat::Cat()
{
	cout << "Cat default constructor" << endl;
	setType("Cat");
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal(src)
{
	cout << "Cat copy constructor" << endl;
	*this = src;
}

Cat::~Cat()
{
	cout << "Cat destructor" << endl;
	delete this->_brain;
}

///////////////////////////
///		OPERATORS		///
///////////////////////////

Cat &Cat::operator=(Cat const &src)
{
	if (this != &src)
	{
		if (this->_brain)
			delete (this->_brain);
		this->_brain = new Brain;
		this->_type = src.getType();
	}
	return (*this);
}

///////////////////////////////
///		GETTERS				///
///////////////////////////////

Brain *Cat::getBrain(void) const
{
	return (this->_brain);
}

///////////////////////////////
///		MEMBER FONCTIONS	///
///////////////////////////////

void Cat::makeSound() const
{
	cout << ANSI_COLOR_GREEN << "Meow! I'm a cat." << ANSI_COLOR_RESET << endl;
}

void Cat::giveIdea(string idea)
{
	for (size_t i = 0; i < 100; i++)
	{
		if (this->_brain->getIdea(i) == "") {
			this->_brain->setIdea(i, idea);
			return ;
		}
	}
	cout << "No more space in the brain of Cat" << endl;
}
void Cat::takeIdea( void ) const
{
	cout << "Cat's idea: " << this->_brain->getIdea(1) << endl;
}