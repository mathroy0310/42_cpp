/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 12:55:09 by maroy                                    */
/*   Updated: 2023/11/09 16:10:10 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "FragTrap.Class.hpp"
#include "ClapTrap.Class.hpp"
#include "FragTrap.Class.hpp"
#include "common.hpp"
#include <iomanip>

int main(void)
{
	{
		cout << ANSI_COLOR_BOLD << "Test 1 ; frag trap prend des degats" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		FragTrap fragtrap("proute");
		fragtrap.takeDamage(5);
		fragtrap.printStatus();
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 2; frag trap se repare" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		FragTrap fragtrap("proute");
		fragtrap.takeDamage(5);

		fragtrap.beRepaired(2);
		fragtrap.printStatus();
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 3 ; clap trap ne peux pas attaquer si il n'a pas assez d'energie" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		FragTrap fragtrap("maroy");
		fragtrap.setEnergyPoints(0);
		fragtrap.printStatus();
		fragtrap.attack("proute");
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 4 ; frag trap ne peux pas attaquer si il est mort" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		FragTrap fragtrap("maroy");
		fragtrap.setHitPoints(0);
		fragtrap.printStatus();
		fragtrap.attack("proute");
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 5 ; frag trap ne peux pas se reparer si il est mort" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		FragTrap fragtrap("maroy");
		fragtrap.setHitPoints(0);
		fragtrap.printStatus();
		fragtrap.beRepaired(10);
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Test 6 ; Constructeur de recopie" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		FragTrap fragtrap("maroy");
		fragtrap.takeDamage(5);
		fragtrap.beRepaired(2);
		FragTrap fragtrap2(fragtrap);
		fragtrap.printStatus();
		fragtrap2.printStatus();
	}

	return (EXIT_SUCCESS);
}