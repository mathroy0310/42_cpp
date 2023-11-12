/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Dog.class.cpp                                     ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:49:40 by maroy                                    */
/*   Updated: 2023/11/11 14:39:10 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Dog.class.hpp"

Dog::Dog()
{
	cout << "Dog default constructor" << endl;
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
	cout << ANSI_COLOR_CYAN << "Woof! I'm a Dog." << ANSI_COLOR_RESET << endl;
}