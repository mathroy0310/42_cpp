/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   WrongCat.cpp                                      ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 19:32:38 by maroy                                    */
/*   Updated: 2023/10/20 19:38:27 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(){
	cout << "WrongCat default constructor called" << endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src){
	cout << "WrongCat copy constructor called" << endl;
	*this = src;
}

WrongCat::~WrongCat(){
	cout << "WrongCat destructor called" << endl;
}

WrongCat & WrongCat::operator=(WrongCat const & src){
	this->_type = src.getType();
	return (*this);
}

void WrongCat::makeSound() const{
	cout << "miaw miaw Im a WrongCat" << endl;
}
