/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   ScavTrap.Class.cpp                                ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 13:30:08 by maroy                                    */
/*   Updated: 2023/11/09 16:10:52 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "ScavTrap.Class.hpp"
#include "common.hpp"

///////////////////////////////////////////////////////////
///														///
///			CONSTRUCTORS AND DESTRUCTORS				///
///														///
///////////////////////////////////////////////////////////

ScavTrap::ScavTrap()
	: ClapTrap("default", 100, 50, 20)
{
	cout << "ScavTrap default constructor called" << endl;
}

ScavTrap::ScavTrap(string name)
	: ClapTrap(name, 100, 50, 20)
{
	cout << "ScavTrap parameter constructor called" << endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	cout << "ScavTrap copy constructor called" << endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap destructor called" << endl;
}

///////////////////////////////////////////////////////////
///														///
///			MEMBERS FONCTIONS							///
///														///
///////////////////////////////////////////////////////////

void ScavTrap::printStatus(void) const
{
	cout << ANSI_COLOR_YELLOW << "ScavTrap " << this->getName() << " has " << this->getHitPoints() << " hit points and " << this->getEnergyPoints() << " energy points." << ANSI_COLOR_RESET << endl;
}

void ScavTrap::attack(string const &target)
{
	if (!this->isEnergy() || !this->isAlive())
	{
		cout << "ScavTrap " << this->getName() << " can't attack!" << endl;
		return ;
	}
	cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getMeleeAttackDamage() << " points of damage!" << endl;
	setEnergyPoints(getEnergyPoints() - 1);
}

void ScavTrap::guardGate(void) const
{
	cout << "ScavTrap " << this->getName() << " has enterred in Gate keeper mode." << endl;
}
