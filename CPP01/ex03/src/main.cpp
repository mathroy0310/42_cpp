/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 18:18:43 by maroy                                    */
/*   Updated: 2023/11/02 16:20:18 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "HumanA.class.hpp"
#include "HumanB.class.hpp"
#include "Weapon.class.hpp"
#include "common.hpp"

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	cout << endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	cout << endl;
	{
		Weapon axe = Weapon("Heavy axe");
		HumanA maroy("Maroy", axe);
		maroy.attack();
		axe.setType("Light axe");
		maroy.attack();
	}
	cout << endl;
	{
		Weapon axe = Weapon("Heavy axe");
		HumanB maroy("Maroy");
		maroy.attack();
		maroy.setName("math2");
		maroy.attack();
		maroy.setWeapon(axe);
		maroy.attack();
		axe.setType("Light axe");
		maroy.attack();
	}
	return (0);
}