/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:41:14 by maroy             #+#    #+#             */
/*   Updated: 2023/10/24 22:16:52 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.class.hpp"

AAnimal::AAnimal()
{
	this->_type = "regular AAnimal";
	// cout << "AAnimal default constructor called" << endl;
}

AAnimal::AAnimal(AAnimal const &src)
{
	// cout << "AAnimal copy constructor called" << endl;
	*this = src;
}

AAnimal::~AAnimal()
{
	// cout << "AAnimal destructor called" << endl;
}

///////////////////////////
///		OPERATORS		///
///////////////////////////

AAnimal &AAnimal::operator=(AAnimal const &src)
{
	this->_type = src.getType();
	return (*this);
}

///////////////////////////////
///		MEMBER FONCTIONS	///
///////////////////////////////

// void AAnimal::makeSound() const
// {
// 	cout << "AAnimal sound ..." << endl;
// }

///////////////////////////////
///		Setters & Getters	///
///////////////////////////////

string AAnimal::getType() const
{
	return (this->_type);
}

void AAnimal::setType(string type)
{
	this->_type = type;
}
