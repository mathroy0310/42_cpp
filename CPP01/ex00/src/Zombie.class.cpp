/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Zombie.class.cpp                                  ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 17:00:35 by maroy                                    */
/*   Updated: 2023/11/02 15:20:20 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Zombie.class.hpp"

// Default Constructor
Zombie::Zombie(string name) : _name(name)
{
	cout << ANSI_COLOR_CYAN << "Zombie " << this->_name << " is born" << ANSI_COLOR_RESET << endl;
}

// Default Destructor
Zombie::~Zombie()
{
	cout << ANSI_COLOR_CYAN << "Zombie " << this->_name << " is dead" << ANSI_COLOR_RESET << endl;
}

// Announce name + "BraiiiiiiinnnzzzZ..."
void Zombie::announce(void) const
{
	cout << this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}