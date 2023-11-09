/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 12:55:09 by maroy                                    */
/*   Updated: 2023/11/09 15:59:26 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "ClapTrap.Class.hpp"
#include "ScavTrap.Class.hpp"
#include "common.hpp"
#include <iomanip>

int main(void)
{
	{
		cout << ANSI_COLOR_BOLD << "Test 1 ; clap trap prend des degats" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ScavTrap scavtrap("proute");
		scavtrap.takeDamage(5);
		scavtrap.printStatus();
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 2; clap trap se repare" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ScavTrap scavtrap("proute");
		scavtrap.takeDamage(5);

		scavtrap.beRepaired(2);
		scavtrap.printStatus();
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 3 ; clap trap ne peux pas attaquer si il n'a pas assez d'energie" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ScavTrap scavtrap("maroy");
		scavtrap.setEnergyPoints(0);
		scavtrap.printStatus();
		scavtrap.attack("proute");
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 4 ; clap trap ne peux pas attaquer si il est mort" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ScavTrap scavtrap("maroy");
		scavtrap.setHitPoints(0);
		scavtrap.printStatus();
		scavtrap.attack("proute");
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 5 ; clap trap ne peux pas se reparer si il est mort" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ScavTrap scavtrap("maroy");
		scavtrap.setHitPoints(0);
		scavtrap.printStatus();
		scavtrap.beRepaired(10);
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 6 ; Constructeur de recopie" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ScavTrap scavtrap("maroy");
		scavtrap.takeDamage(5);
		scavtrap.beRepaired(2);
		ScavTrap scavtrap2(scavtrap);
		scavtrap.printStatus();
		scavtrap2.printStatus();
	}

	return (EXIT_SUCCESS);
}