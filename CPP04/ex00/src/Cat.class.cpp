/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:48:37 by maroy             #+#    #+#             */
/*   Updated: 2023/11/13 18:03:54 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

Cat::Cat()
{
    cout << "Cat default constructor" << endl;
    setType("Cat");
}

Cat::Cat(Cat const &src) : Animal(src)
{
    cout << "Cat copy constructor" << endl;
    *this = src;
}

Cat::~Cat()
{
    cout << "Cat destructor" << endl;
}

Cat &
Cat::operator=(Cat const &src)
{
    if (this != &src)
        this->_type = src.getType();
    return (*this);
}

void
Cat::makeSound() const
{
    cout << ANSI_COLOR_GREEN << "Meow! I'm a cat." << ANSI_COLOR_RESET << endl;
}