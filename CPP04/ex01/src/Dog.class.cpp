/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:49:40 by maroy             #+#    #+#             */
/*   Updated: 2023/11/13 18:06:06 by maroy            ###   ########.fr       */
/*                                                                            */
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

Dog::Dog(Dog &ref) : Animal(ref)
{
    cout << "Dog copy constructor" << endl;
    setType(ref.getType());
    this->_brain = new Brain(*(ref.getBrain()));
}

Dog::~Dog()
{
    cout << "Dog destructor" << endl;
    if (this->_brain)
        delete this->_brain;
}

///////////////////////////
///		OPERATORS		///
///////////////////////////

Dog &
Dog::operator=(Dog const &src)
{
    cout << "Dog Copy Operator" << endl;
    this->_type = src.getType();
    if (this->_brain)
        delete (this->_brain);
    this->_brain = new Brain(*(src.getBrain()));
    return *this;
}

Brain *
Dog::getBrain(void) const
{
    return (this->_brain);
}

///////////////////////////////
///		MEMBER FONCTIONS	///
///////////////////////////////

void
Dog::makeSound() const
{
    cout << ANSI_COLOR_CYAN << "Woof! I'm a Dog." << ANSI_COLOR_RESET << endl;
}

void
Dog::giveIdea(string idea)
{
    for (int i = 0; i < 100; i++)
    {
        if (this->_brain->getIdea(i) == "")
        {
            this->_brain->setIdea(i, idea);
            return;
        }
    }
    cout << "No more space in the brain of Dog" << endl;
}

void
Dog::printIdeas(void) const
{
    string str;
    cout << "Dog's ideas:" << endl;
    for (int i = 0; i < 100; i++)
    {
        str = this->_brain->getIdea(i);
        if (str.empty())
            return;
        cout << ANSI_COLOR_BRIGHT_MAGENTA << str << ANSI_COLOR_RESET << endl;
    }
}