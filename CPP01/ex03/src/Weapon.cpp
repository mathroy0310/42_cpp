/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Weapon.cpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 18:17:59 by maroy                                    */
/*   Updated: 2023/10/14 18:29:55 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(string type) {
	this->_type = type;
}

Weapon::~Weapon(){}

// #=- Getters -=# //
string	Weapon::getType(void) {
	return (this->_type);
}

// #=- Setters -=# //
void 	Weapon::setType(string type) {
	this->_type = type;
}