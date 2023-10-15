/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   HumanB.cpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 18:22:25 by maroy                                    */
/*   Updated: 2023/10/14 18:49:20 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"
#include "../inc/HumanB.hpp"

HumanB::HumanB(string name) {
	this->_name = name;
}

HumanB::~HumanB(){}

// #=- Getters -=# //

string	HumanB::getName(void) {
	return (this->_name);
}

Weapon	*HumanB::getWeapon(void) {
	return (this->_weapon);
}

// #=- Setters -=# //

void	HumanB::setName(string name) {
	this->_name = name;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

// #=- Actions -=# //

void	HumanB::attack(void) {
	cout << this->_name << " attacks with his " << this->_weapon->getType() << endl;
}