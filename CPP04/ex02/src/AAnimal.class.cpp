/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:41:14 by maroy             #+#    #+#             */
/*   Updated: 2023/11/13 17:43:03 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.class.hpp"

AAnimal::AAnimal()
{
    // cout << "Animal default constructor called" << endl;
    this->_type = "regular Animal";
}

AAnimal::AAnimal(AAnimal const &src)
{
    // cout << "Animal copy constructor called" << endl;
    *this = src;
}

AAnimal::~AAnimal()
{
    // cout << "Animal destructor called" << endl;
}

///////////////////////////
///		OPERATORS		///
///////////////////////////

AAnimal &
AAnimal::operator=(AAnimal const &src)
{
    this->_type = src.getType();
    return (*this);
}

///////////////////////////////
///		MEMBER FONCTIONS	///
///////////////////////////////

// void
// AAnimal::makeSound() const
// {
//     cout << "AAnimal sound ..." << endl;
// }

///////////////////////////////
///		Setters & Getters	///
///////////////////////////////

string
AAnimal::getType() const
{
    return (this->_type);
}

void
AAnimal::setType(string type)
{
    this->_type = type;
}

bool
AAnimal::isAbstract(void) const
{
    return (false);
}