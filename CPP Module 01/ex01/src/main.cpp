/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 16:52:32 by maroy                                    */
/*   Updated: 2023/10/14 17:51:41 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int		main(void)
{
	Zombie	*zombie;

	zombie = newZombie("Maroy");
	zombie->announce();
	delete zombie;
	randomChump("Maroy");
	zombie = zombieHorde(5, "Maroy");
	for (int i = 0; i < 5; i++)
		zombie[i].announce();
	return (0);
}