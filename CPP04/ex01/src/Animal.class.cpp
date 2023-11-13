/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:41:14 by maroy             #+#    #+#             */
/*   Updated: 2023/11/13 18:06:32 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"

Animal::Animal()
{
    // cout << "Animal default constructor called" << endl;
    this->_type = "regular Animal";
}

Animal::Animal(Animal const &src)
{
    // cout << "Animal copy constructor called" << endl;
    *this = src;
}

Animal::~Animal()
{
    // cout << "Animal destructor called" << endl;
}

///////////////////////////
///		OPERATORS		///
///////////////////////////

Animal &
Animal::operator=(Animal const &src)
{
    this->_type = src.getType();
    return (*this);
}

///////////////////////////////
///		MEMBER FONCTIONS	///
///////////////////////////////

void
Animal::makeSound() const
{
    cout << ANSI_COLOR_BRIGHT_RED << "Animal sound ..." << ANSI_COLOR_RESET
         << endl;
}

///////////////////////////////
///		Setters & Getters	///
///////////////////////////////

string
Animal::getType() const
{
    return (this->_type);
}

void
Animal::setType(string type)
{
    this->_type = type;
}
