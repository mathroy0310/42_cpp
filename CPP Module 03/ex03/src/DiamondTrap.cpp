/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   DiamondTrap.cpp                                   ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 16:51:10 by maroy                                    */
/*   Updated: 2023/10/20 18:28:37 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"
#include "../inc/DiamondTrap.hpp"

///////////////////////////////////////////////////////////////
///															///
///			CONSTRUCTORS AND DESTRUCTORS					///
///															///
///////////////////////////////////////////////////////////////

DiamondTrap::DiamondTrap(){
	cout << "DiamondTrap default constructor called" << endl;
}

DiamondTrap::DiamondTrap(string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
    cout << "DiamondTrap " << name << " is born!" << std::endl;
    hitPoints = FragTrap:;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

