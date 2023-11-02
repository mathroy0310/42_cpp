/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   HumanB.class.cpp                                  ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 18:22:25 by maroy                                    */
/*   Updated: 2023/11/02 15:34:17 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "HumanB.class.hpp"
#include "Weapon.class.hpp"

HumanB::HumanB(string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

// #=- Getters -=# //

string HumanB::getName(void)
{
	return (this->_name);
}

Weapon *HumanB::getWeapon(void)
{
	return (this->_weapon);
}

// #=- Setters -=# //

void HumanB::setName(string name)
{
	this->_name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

// #=- Actions -=# //

void HumanB::attack(void)
{
	if (this->_weapon == NULL)
		cout << this->_name << " has no weapon" << endl;
	else
		cout << this->_name << " attacks with his " << this->_weapon->getType() << endl;
}