/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 12:55:09 by maroy                                    */
/*   Updated: 2023/11/08 16:30:46 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"
#include "common.hpp"
#include <iomanip>

int	main(void)
{
	{
		cout << ANSI_COLOR_BOLD << "Test 1 ; clap trap ne peux pas avoir moins de 0 points de vie" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ClapTrap claptrap("proute");
		claptrap.takeDamage(50);
		claptrap.printStatus();
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 2 ; clap trap ne peux pas reparer plus de point que son max" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ClapTrap claptrap("maroy");
		claptrap.takeDamage(5);
		claptrap.beRepaired(10);
		claptrap.printStatus();
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 3 ; clap trap ne peux pas attaquer si il n'a pas assez d'energie" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ClapTrap claptrap("maroy");
		claptrap.setEnergyPoints(0);
		claptrap.printStatus();
		claptrap.attack("proute");
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 4 ; clap trap ne peux pas attaquer si il est mort" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ClapTrap claptrap("maroy");
		claptrap.setHitPoints(0);
		claptrap.printStatus();
		claptrap.attack("proute");
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 5 ; clap trap ne peux pas se reparer si il est mort" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ClapTrap claptrap("maroy");
		claptrap.setHitPoints(0);
		claptrap.printStatus();
		claptrap.beRepaired(10);
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 6 ; Constructeur de recopie" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ClapTrap claptrap("maroy");
		claptrap.takeDamage(5);
		claptrap.beRepaired(2);
		ClapTrap claptrap2(claptrap);
		claptrap.printStatus();
		claptrap2.printStatus();
	}

	return (EXIT_SUCCESS);
}