/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 16:52:32 by maroy                                    */
/*   Updated: 2023/10/26 18:24:54 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Zombie.class.hpp"

int	main(void)
{
	Zombie *zombie;

	zombie = newZombie("Maroy");
	zombie->announce();
	delete zombie;
	randomChump("Maroy");
	return (EXIT_SUCCESS);
}