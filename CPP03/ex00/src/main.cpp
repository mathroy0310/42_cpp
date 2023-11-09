/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 12:55:09 by maroy                                    */
/*   Updated: 2023/11/09 15:22:58 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "ClapTrap.Class.hpp"
#include "common.hpp"
#include <iomanip>

int main(void)
{
	{
		cout << ANSI_COLOR_BOLD << "Test 1 ; clap trap prend des degats" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ClapTrap claptrap("proute");
		claptrap.takeDamage(5);
		claptrap.printStatus();
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 2; clap trap se repare" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		ClapTrap claptrap("proute");
		claptrap.takeDamage(5);

		claptrap.beRepaired(2);
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

	return (0);
}