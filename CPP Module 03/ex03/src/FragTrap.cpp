/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   FragTrap.cpp                                      ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 14:50:54 by maroy                                    */
/*   Updated: 2023/10/19 15:08:00 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"
#include "../inc/FragTrap.hpp"

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

void			FragTrap::printStatus( void ){
	cout << ANSI_COLOR_BOLD << "FragTrap " << this->getName() << " has " << this->getHitPoints() << " hit points and " << this->getEnergyPoints() << " energy points."<< ANSI_COLOR_RESET << endl;
}

void			FragTrap::highFivesGuys( void ){
	cout << "FragTrap " << this->getName() << " has requested a high five!" << endl;
}