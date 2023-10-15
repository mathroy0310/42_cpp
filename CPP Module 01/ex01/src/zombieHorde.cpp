/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   zombieHorde.cpp                                   ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 17:29:35 by maroy                                    */
/*   Updated: 2023/10/14 17:53:29 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie*	zombieHorde( int N, string name ){
	Zombie *zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombie[i].setName(name + to_string(i));
	return (zombie);
}