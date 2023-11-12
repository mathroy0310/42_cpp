/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Animal.class.cpp                                  ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:41:14 by maroy                                    */
/*   Updated: 2023/11/11 14:21:00 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Animal.class.hpp"

Animal::Animal()
{
	cout << "Animal default constructor called" << endl;
	this->_type = "regular Animal";
}

Animal::Animal(Animal const &src)
{
	cout << "Animal copy constructor called" << endl;
	*this = src;
}

Animal::~Animal()
{
	cout << "Animal destructor called" << endl;
}

Animal &Animal::operator=(Animal const &src)
{
	this->_type = src.getType();
	return (*this);
}
void Animal::makeSound() const
{
	cout << "Animal sound ..." << endl;
}

string Animal::getType() const
{
	return (this->_type);
}

void Animal::setType(string type)
{
	this->_type = type;
}
