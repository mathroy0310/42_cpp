/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Zombie.hpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 16:53:25 by maroy                                    */
/*   Updated: 2023/10/14 17:52:49 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "common.hpp"

class	Zombie
{
	
	public:

		Zombie( string name );
		Zombie( void );
		~Zombie();
		void	announce( void ) const;
		void	setName( string name );
		

	private:

		string	_name;

};

Zombie *newZombie( string name );
void	randomChump( string name );
Zombie *zombieHorde( int N, string name );

#endif // ZOMBIE_HPP