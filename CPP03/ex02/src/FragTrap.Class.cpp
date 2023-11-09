/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   FragTrap.Class.cpp                                ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 14:50:54 by maroy                                    */
/*   Updated: 2023/11/09 16:10:15 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "common.hpp"
#include "FragTrap.Class.hpp"

///////////////////////////////////////////////////////////
///														///
///			CONSTRUCTORS AND DESTRUCTORS				///
///														///
///////////////////////////////////////////////////////////

FragTrap::FragTrap(): ClapTrap("default", 100, 100, 30){
	cout << "FragTrap default constructor called" << endl;
}

FragTrap::FragTrap(string name): ClapTrap(name, 100, 100, 30){
	cout << "FragTrap parameter constructor called" << endl;
}

FragTrap::FragTrap(FragTrap const & src){
	cout << "FragTrap copy constructor called" << endl;
	*this = src;
}

FragTrap::~FragTrap(){
	cout << "FragTrap destructor called" << endl;
}

///////////////////////////////////////////////////////////
///														///
///			MEMBERS FONCTIONS							///
///														///
///////////////////////////////////////////////////////////

void			FragTrap::printStatus( void ) const {
	cout << ANSI_COLOR_MAGENTA << "FragTrap " << this->getName() << " has " << this->getHitPoints() << " hit points and " << this->getEnergyPoints() << " energy points."<< ANSI_COLOR_RESET << endl;
}

void			FragTrap::highFivesGuys( void ) const {
	cout << "FragTrap " << this->getName() << " has requested a high five!" << endl;
}