/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 12:55:09 by maroy                                    */
/*   Updated: 2023/10/19 13:26:45 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/common.hpp"

int main(void)
{
	ClapTrap claptrap("proute");
	while (claptrap.isAlive())
	{
		claptrap.attack("target");
		claptrap.takeDamage(1);
		claptrap.beRepaired(1);
		claptrap.printStatus();
	}

	return (0);
}