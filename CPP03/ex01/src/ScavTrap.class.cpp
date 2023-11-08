/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   ScavTrap.class.cpp                                ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 13:30:08 by maroy                                    */
/*   Updated: 2023/11/08 17:01:28 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"
#include "common.hpp"

static const unsigned int _max_hit_points = 100;
static const unsigned int _max_energy_points = 50;
static const unsigned int _attack_damage = 20;

///////////////////////////////////////////////////////////
///														///
///			CONSTRUCTORS AND DESTRUCTORS				///
///														///
///////////////////////////////////////////////////////////

ScavTrap::ScavTrap(): ClapTrap("default", 100, 50, 20){
	cout << "ScavTrap default constructor called" << endl;
}

ScavTrap::ScavTrap(string name): ClapTrap(name, 100, 50, 20){
	cout << "ScavTrap parameter constructor called" << endl;
}

ScavTrap::ScavTrap(ScavTrap const & src){
	cout << "ScavTrap copy constructor called" << endl;
	*this = src;
}

ScavTrap::~ScavTrap(){
	cout << "ScavTrap destructor called" << endl;
}


///////////////////////////////////////////////////////////
///														///
///			MEMBERS FONCTIONS							///
///														///
///////////////////////////////////////////////////////////

void 			ScavTrap::attack(string const &target)
{
	if (!this->isEnergy())
	{
		cout << "ScavTrap " << this->getName() << " has not enough energy points to attack!" << endl;
		return ;
	}
	if (!this->isAlive())
	{
		cout << "ScavTrap " << this->getName() << " is dead, ScavTraps can't attack when dead ..." << endl;
		return ;
	}
	ClapTrap::setEnergyPoints(getEnergyPoints() - 1);
	cout << "ScavTrap " << this->getName() << " attacks " << target << ",causing " << this->getMeleeAttackDamage() << " points of damage !" << endl;
}
void			ScavTrap::guardGate( void ){
	cout << "ScavTrap " << this->getName() << " has enterred in Gate keeper mode." << endl;
}
