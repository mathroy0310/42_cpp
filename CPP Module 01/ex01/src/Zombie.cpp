/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Zombie.cpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 17:00:35 by maroy                                    */
/*   Updated: 2023/10/14 17:54:59 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

//Default Constructor
void	randomChump( string name ){
	Zombie zombie(name);
	zombie.announce();
}

Zombie *newZombie( string name ){
	Zombie *zombie = new Zombie(name);
	return (zombie);	
}

Zombie::Zombie( string name ) : _name(name) {
	if (DEBUG)
		cout  << ANSI_COLOR_CYAN << "DEBUG " << "Zombie " << this->_name << " is born" << ANSI_COLOR_RESET << std::endl;
}

Zombie::Zombie( void ){
	this->_name = "(null)";
	if (DEBUG)
		cout  << ANSI_COLOR_CYAN << "DEBUG " << "Zombie " << this->_name << " is born" << ANSI_COLOR_RESET << std::endl;
}

//Default Destructor
Zombie::~Zombie(){
	if (DEBUG)
		cout << ANSI_COLOR_CYAN << "DEBUG "  << "Zombie " << this->_name << " is dead" << ANSI_COLOR_RESET << std::endl;
}

void Zombie::setName( string name ){
	this->_name = name;
}

//Announce name + "BraiiiiiiinnnzzzZ..."
void	Zombie::announce( void ) const{
	cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}