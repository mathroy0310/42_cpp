/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Dog.class.cpp                                     ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:49:40 by maroy                                    */
/*   Updated: 2023/11/11 17:12:13 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Dog.class.hpp"

///////////////////////////////////
///	CONSTRUCTORS & DESTRUCTOR	///
///////////////////////////////////

Dog::Dog()
{
	cout << "Dog default constructor" << endl;
	setType("Dog");
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal(src)
{
	cout << "Dog copy constructor" << endl;
	*this = src;
}

Dog::~Dog()
{
	cout << "Dog destructor" << endl;
	delete this->_brain;
}

///////////////////////////
///		OPERATORS		///
///////////////////////////

Dog &Dog::operator=(Dog const &src)
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
///		Getters				///
///////////////////////////////

Brain *Dog::getBrain(void) const
{
	return (this->_brain);
}

///////////////////////////////
///		MEMBER FONCTIONS	///
///////////////////////////////

void Dog::makeSound() const
{
	cout << ANSI_COLOR_CYAN << "Woof! I'm a Dog." << ANSI_COLOR_RESET << endl;
}

void Dog::giveIdea(string idea)
{
	for (size_t i = 0; i < 100; i++)
	{
		if (this->_brain->getIdea(i) == "") {
			this->_brain->setIdea(i, idea);
			return ;
		}
	}
	cout << "No more space in the brain of Dog" << endl;
}

void Dog::printIdeas( void ) const
{
	string idea;
	cout << "Dog's ideas:" << endl;
	for (size_t i = 0; i < 100; i++)
	{
		idea = this->_brain->getIdea(i);
		if (idea.empty())
			return ;
		cout << "Idea " << i << ": " << idea << endl;
	}
}