/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:49:40 by maroy             #+#    #+#             */
/*   Updated: 2023/10/24 22:12:41 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

Dog::Dog()
{
	setType("Dog");
}

Dog::Dog(Dog const &src)
{
	cout << "Dog copy constructor" << endl;
	*this = src;
}

Dog::~Dog()
{
	cout << "Dog destructor" << endl;
}

Dog &Dog::operator=(Dog const &src)
{
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

void Dog::makeSound() const
{
	cout << "Woof! I'm a Dog." << endl;
}