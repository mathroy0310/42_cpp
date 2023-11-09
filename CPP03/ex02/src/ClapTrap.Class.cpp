/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   ClapTrap.Class.cpp                                ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 12:16:57 by maroy                                    */
/*   Updated: 2023/11/09 16:10:19 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "ClapTrap.Class.hpp"
#include "common.hpp"

///////////////////////////////////////////////////////////
///														///
///			CONSTRUCTORS AND DESTRUCTORS				///
///														///
///////////////////////////////////////////////////////////

ClapTrap::ClapTrap()
	: _name("default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	cout << "ClapTrap default constructor called" << endl;
}

ClapTrap::ClapTrap(string name)
	: _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	cout << "ClapTrap parameter constructor called" << endl;
}

ClapTrap::ClapTrap(string name, int hit_points, unsigned int energy_points, unsigned int attack_damage)	
	: _name(name), _hit_points(hit_points), _energy_points(energy_points), _attack_damage(attack_damage)
{
	cout << "ClapTrap parameter constructor called" << endl;
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
	if (!this->isEnergy() || !this->isAlive())
	{
		cout << "ClapTrap " << this->getName() << " can't attack!" << endl;
		return ;
	}
	cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getMeleeAttackDamage() << " points of damage !" << endl;
	setEnergyPoints(getEnergyPoints() - 1);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->isAlive())
	{
		cout << "ClapTrap " << this->getName() << " is dead" << endl;
		setHitPoints(0);
		return ;
	}
	if (amount > this->getHitPoints())
		amount = this->getHitPoints();
	cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage!" << endl;
	setHitPoints(getHitPoints() - amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->isEnergy() || !this->isAlive())
	{
		cout << "ClapTrap " << this->getName() << " can't be repaired!" << endl;
		return ;
	}
	cout << "ClapTrap " << this->getName() << " is repaired for " << amount << " points of damage!" << endl;
	setHitPoints(getHitPoints() + amount);
	setEnergyPoints(getEnergyPoints() - 1);
}
