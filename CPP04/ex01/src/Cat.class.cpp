/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:48:37 by maroy             #+#    #+#             */
/*   Updated: 2023/11/13 18:04:49 by maroy            ###   ########.fr       */
/*                                                                            */
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

Cat::Cat(Cat &ref) : Animal(ref)
{
    cout << "Cat copy constructor" << endl;
    setType(ref.getType());
    this->_brain = new Brain(*(ref.getBrain()));
}

Cat::~Cat()
{
    cout << "Cat destructor" << endl;
    if (this->_brain)
        delete this->_brain;
}

///////////////////////////
///		OPERATORS		///
///////////////////////////

Cat &
Cat::operator=(Cat const &src)
{
    cout << "Cat Copy Operator" << endl;
    this->_type     = src.getType();
	if (this->_brain)
		delete (this->_brain);
	this->_brain = new Brain(*(src.getBrain()));
    return (*this);
}

Brain *
Cat::getBrain(void) const
{
    return (this->_brain);
}

///////////////////////////////
///		MEMBER FONCTIONS	///
///////////////////////////////

void
Cat::makeSound() const
{
    cout << ANSI_COLOR_GREEN << "Meow! I'm a cat." << ANSI_COLOR_RESET << endl;
}

void
Cat::giveIdea(string idea)
{
    for (size_t i = 0; i < 100; i++)
    {
        if (this->_brain->getIdea(i) == "")
        {
            this->_brain->setIdea(i, idea);
            return;
        }
    }
    cout << "No more space in the brain of Cat" << endl;
}

void
Cat::printIdeas(void) const
{
    string str;
    cout << "Cat's ideas:" << endl;
    for (int i = 0; i < 100; i++)
    {
        str = this->_brain->getIdea(i);
        if (str.empty())
            return;
        cout << ANSI_COLOR_BRIGHT_MAGENTA << str << ANSI_COLOR_RESET << endl;
    }
}