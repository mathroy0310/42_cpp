/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   ScavTrap.cpp                                      ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 13:30:08 by maroy                                    */
/*   Updated: 2023/10/19 16:47:46 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"
#include "../inc/ScavTrap.hpp"

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

void			ScavTrap::printStatus( void ){
	cout << ANSI_COLOR_BOLD << "ScavTrap " << this->getName() << " has " << this->getHitPoints() << " hit points and " << this->getEnergyPoints() << " energy points."<< ANSI_COLOR_RESET << endl;
}

void			ScavTrap::attack (string const &target ){
	if (this->isEnergy())
	{
		cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getMeleeAttackDamage() << " points of damage!" << endl;
		setEnergyPoints(getEnergyPoints() - 1);
		return ;
	}
	cout << "ScavTrap " << this->getName() << " has not enough energy points to attack!" << endl;
}

void			ScavTrap::guardGate( void ){
	cout << "ScavTrap " << this->getName() << " has enterred in Gate keeper mode." << endl;
}
