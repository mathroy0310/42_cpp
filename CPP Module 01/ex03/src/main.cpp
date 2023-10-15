/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 18:18:43 by maroy                                    */
/*   Updated: 2023/10/14 18:48:10 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"
#include "../inc/Weapon.hpp"
#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon axe = Weapon("Heavy axe");
		HumanA maroy("Maroy", axe);
		maroy.attack();
		axe.setType("Light axe");
		maroy.attack();
	}
	{
		Weapon axe = Weapon("Heavy axe");
		HumanB maroy("Maroy");
		maroy.setWeapon(axe);
		maroy.attack();
		axe.setType("Light axe");
		maroy.attack();
	}
	return 0;
}