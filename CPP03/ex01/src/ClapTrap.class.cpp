/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   ClapTrap.class.cpp                                ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 12:16:57 by maroy                                    */
/*   Updated: 2023/11/08 16:59:21 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"
#include "common.hpp"


static const unsigned int _max_hit_points = 10;
static const unsigned int _max_energy_points = 10;
static const unsigned int _attack_damage = 0;

///////////////////////////////////////////////////////////
///														///
///			CONSTRUCTORS AND DESTRUCTORS				///
///														///
///////////////////////////////////////////////////////////

ClapTrap::ClapTrap()
{
	cout << "ClapTrap default constructor called" << endl;
	setName("default");
	setHitPoints(10);
	setEnergyPoints(10);
	setMeleeAttackDamage(0);
}

ClapTrap::ClapTrap(string name) : _name(name), _hit_points(_max_hit_points), _energy_points(_max_energy_points)
{
	cout << "ClapTrap name parameter constructor called" << endl;
}
ClapTrap::ClapTrap(string name, unsigned int hit_points, unsigned int energy_points, unsigned int attack_damage) : _name(name), _hit_points(hit_points), _energy_points(energy_points)
{
	cout << "Claptrap parameters constructor called" << endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	cout << "ClapTrap copy constructor called" << endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap destructor called" << endl;
}

////////////////////////////////////////////////////////////
///														///
///			OPERATION OVERLOAD							///
///														///
///////////////////////////////////////////////////////////

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	cout << "ClapTrap assignation operator called" << endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hit_points = rhs.getHitPoints();
		this->_energy_points = rhs.getEnergyPoints();
		this->_attack_damage = rhs.getMeleeAttackDamage();
	}
	return (*this);
}

///////////////////////////////////////////////////////////
///														///
///			GETTERS										///
///														///
///////////////////////////////////////////////////////////

string ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return (this->_hit_points);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energy_points);
}

unsigned int ClapTrap::getMeleeAttackDamage(void) const
{
	return (this->_attack_damage);
}

///////////////////////////////////////////////////////////
///														///
///			SETTERS										///
///														///
///////////////////////////////////////////////////////////

void ClapTrap::setName(string name)
{
	this->_name = name;
}

void ClapTrap::setHitPoints(unsigned int hit_points)
{
	this->_hit_points = hit_points;
}

void ClapTrap::setEnergyPoints(unsigned int energy_points)
{
	this->_energy_points = energy_points;
}

void ClapTrap::setMeleeAttackDamage(unsigned int attack_damage)
{
	this->_attack_damage = attack_damage;
}

///////////////////////////////////////////////////////////
///														///
///			MEMBERS FONCTIONS							///
///														///
///////////////////////////////////////////////////////////

bool ClapTrap::isAlive(void) const
{
	if (this->getHitPoints() > 0)
		return (true);
	return (false);
}

bool ClapTrap::isEnergy(void) const
{
	if (this->getEnergyPoints() > 0)
		return (true);
	return (false);
}

void ClapTrap::printStatus(void) const
{
	cout << ANSI_COLOR_BRIGHT_CYAN << "ClapTrap " << this->getName() << " has " << this->getHitPoints() << " hit points and " << this->getEnergyPoints() << " energy points." << ANSI_COLOR_RESET << endl;
}

void ClapTrap::attack(string const &target)
{
	if (!this->isEnergy())
	{
		cout << "ClapTrap " << this->getName() << " has not enough energy points to attack!" << endl;
		return ;
	}
	if (!this->isAlive())
	{
		cout << "ClapTrap " << this->getName() << " is dead, Claptraps can't attack when dead ..." << endl;
		return ;
	}
	ClapTrap::setEnergyPoints(getEnergyPoints() - 1);
	cout << "ClapTrap " << this->getName() << " attacks " << target << ",causing " << this->getMeleeAttackDamage() << " points of damage !" << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->isAlive())
	{
		if (amount > this->getHitPoints())
			amount = this->getHitPoints();
		cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage!" << endl;
		ClapTrap::setHitPoints(getHitPoints() - amount);
		return ;
	}
	cout << "ClapTrap " << this->getName() << " is dead" << endl;
	ClapTrap::setHitPoints(0);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->isEnergy())
	{
		cout << "ClapTrap " << this->getName() << " has not enough energy points to be repaired!" << endl;
		return ;
	}
	if (!this->isAlive())
	{
		cout << "ClapTrap " << this->getName() << " is dead, Claptraps can't be repaired when dead ..." << endl;
		return ;
	}
	if (this->getHitPoints() + amount > 10)
		amount = 10 - this->getHitPoints();
	cout << "ClapTrap " << this->getName() << " is repaired for " << amount << " points of damage!" << endl;
	ClapTrap::setHitPoints(getHitPoints() + amount);
	ClapTrap::setEnergyPoints(getEnergyPoints() - 1);
}
