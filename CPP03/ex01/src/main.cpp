/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 12:55:09 by maroy                                    */
/*   Updated: 2023/11/08 16:49:52 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include "common.hpp"
#include <iomanip>

int	main(void)
{
	{
		cout << ANSI_COLOR_BOLD << "Test 1 ; Scavtrap ne peux pas avoir moins de 0 points de vie" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ScavTrap scavtrap("proute");
		scavtrap.takeDamage(50);
		scavtrap.printStatus();
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 2 ; Scavtrap ne peux pas reparer plus de point que son max" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ScavTrap scavtrap("maroy");
		scavtrap.takeDamage(5);
		scavtrap.beRepaired(10);
		scavtrap.printStatus();
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 3 ; Scavtrap ne peux pas attaquer si il n'a pas assez d'energie" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ScavTrap scavtrap("maroy");
		scavtrap.setEnergyPoints(0);
		scavtrap.printStatus();
		scavtrap.attack("proute");
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 4 ; Scavtrap ne peux pas attaquer si il est mort" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ScavTrap scavtrap("maroy");
		scavtrap.setHitPoints(0);
		scavtrap.printStatus();
		scavtrap.attack("proute");
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 5 ; Scavtrap ne peux pas se reparer si il est mort" << ANSI_COLOR_RESET << endl;
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