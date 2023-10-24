/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Zombie.cpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 17:00:35 by maroy                                    */
/*   Updated: 2023/10/24 17:18:46 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

//Default Constructor
Zombie::Zombie(string name)
	: _name(name)
{
	if (DEBUG)
		cout << ANSI_COLOR_CYAN << "DEBUG "
				<< "Zombie " << this->_name << " is born" << ANSI_COLOR_RESET << std::endl;
}

//Default Destructor
Zombie::~Zombie()
{
	if (DEBUG)
		cout << ANSI_COLOR_CYAN << "DEBUG "
				<< "Zombie " << this->_name << " is dead" << ANSI_COLOR_RESET << std::endl;
}

//Announce name + "BraiiiiiiinnnzzzZ..."
void Zombie::announce(void) const
{
	cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}