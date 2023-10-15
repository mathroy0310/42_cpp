/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   HumanA.cpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 18:23:48 by maroy                                    */
/*   Updated: 2023/10/14 18:46:27 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"
#include "../inc/HumanA.hpp"

HumanA::HumanA(string name, Weapon &weapon): _weapon(&weapon){
	this->_name = name;
	this->_weapon = &weapon;
}

HumanA::~HumanA(){}

// #=- Getters -=# //

string	HumanA::getName(void) {
	return (this->_name);
}

Weapon *HumanA::getWeapon(void) {
	return (this->_weapon);
}

// #=- Setters -=# //

void	HumanA::setName(string name) {
	this->_name = name;
}

void HumanA::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

// #=- Actions -=# //

void	HumanA::attack(void) {
	cout << this->_name << " attacks with his " << this->_weapon->getType() << endl;
}
