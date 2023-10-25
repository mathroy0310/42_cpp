/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:48:37 by maroy             #+#    #+#             */
/*   Updated: 2023/10/24 22:06:22 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

///////////////////////////////////
///	CONSTRUCTORS & DESTRUCTOR	///
///////////////////////////////////

Cat::Cat()
{
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
	cout << "Meow! I'm a cat." << endl;
}

void Cat::compareTo(Cat const &other_cat) const
{
	cout << endl;
	cout << "Now comparing two cats\n";
	cout << "My brain's heap address: " << static_cast<void *>(this->_brain) << endl;
	cout << "Other's heap address: " << static_cast<void *>(other_cat.getBrain()) << endl;
	cout << endl;
	cout << "My brain's ideas \t\t | \t\t\t Other brain's ideas\n";
	for (int i = 0; i < 100; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < 100; i++)
		cout << ((this->_brain)->getIdeas())[i] << "\t\t\t | \t\t\t" << ((other_cat.getBrain())->getIdeas())[i] << endl;
	cout << endl;
}