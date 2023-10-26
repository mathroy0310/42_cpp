/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 12:55:09 by maroy                                    */
/*   Updated: 2023/10/19 14:49:34 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/common.hpp"


#include <unistd.h>
int main(void)
{
	ClapTrap claptrap("proute");

	ScavTrap scavtrap("proute2");

	
	
	// while (claptrap.isAlive())
	// {
	// 	claptrap.attack("target");
	// 	claptrap.takeDamage(1);
	// 	claptrap.beRepaired(1);
	// 	claptrap.printStatus();
	// }


	while(scavtrap.isAlive())
	{
		scavtrap.attack("target");
		scavtrap.takeDamage(15);
		scavtrap.beRepaired(15);
		scavtrap.printStatus();
	}
	scavtrap.attack("target");
	scavtrap.takeDamage(15);
	scavtrap.beRepaired(15);
	scavtrap.printStatus();
	scavtrap.guardGate();


	return (0);
}