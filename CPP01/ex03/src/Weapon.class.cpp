/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Weapon.class.cpp                                  ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 18:17:59 by maroy                                    */
/*   Updated: 2023/11/02 16:27:24 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Weapon.class.hpp"

Weapon::Weapon(string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{
}

// #=- Getters -=# //
const string &Weapon::getType(void) const
{
	return (this->_type);
}

// #=- Setters -=# //
void Weapon::setType(string type)
{
	this->_type = type;
}