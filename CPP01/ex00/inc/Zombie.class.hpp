/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Zombie.class.hpp                                  ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 16:53:25 by maroy                                    */
/*   Updated: 2023/10/26 13:58:02 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "common.hpp"

class Zombie
{
  public:
	Zombie(string name);
	~Zombie();
	void announce(void) const;

  private:
	string _name;
};

Zombie	*newZombie(string name);
void	randomChump(string name);

#endif // ZOMBIE_HPP