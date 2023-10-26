/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:49:40 by maroy             #+#    #+#             */
/*   Updated: 2023/10/24 22:20:23 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

///////////////////////////////////
///	CONSTRUCTORS & DESTRUCTOR	///
///////////////////////////////////

Dog::Dog()
{
	setType("Dog");
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src) : AAnimal(src)
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
	cout << "Woof! I'm a Dog." << endl;
}

void Dog::compareTo(Dog const &other_dog) const
{
	cout << endl;
	cout << "Now comparing two dogs\n";
	cout << "My brain's heap address: " << static_cast<void *>(this->_brain) << endl;
	cout << "Other's heap address: " << static_cast<void *>(other_dog.getBrain()) << endl;
	cout << endl;
	cout << "My brain's ideas \t\t | \t\t\t Other brain's ideas\n";
	for (int i = 0; i < 100; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < 100; i++)
		cout << ((this->_brain)->getIdeas())[i] << "\t\t\t | \t\t\t" << ((other_dog.getBrain())->getIdeas())[i] << endl;
	cout << endl;
}