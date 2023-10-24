/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Brain.cpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/24 11:38:28 by maroy                                    */
/*   Updated: 2023/10/24 11:49:22 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Brain.hpp"

///////////////////////////////////
///	CONSTRUCTORS & DESTRUCTOR	///
///////////////////////////////////

Brain::Brain(){
	//cout << "Brain default constructor called" << endl;
}

Brain::Brain(Brain const &src) {
	*this = src;
}

Brain::~Brain(){}

///////////////////////////
///		OPERATORS		///
///////////////////////////
 
Brain & Brain::operator=(Brain const & src) {
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return (*this);
}

///////////////////////////
///	Setters & Getters	///
///////////////////////////

string	*Brain::getIdeas( void ){
	return (this->_ideas);
}

void	Brain::setIdeas(int i, string *ideas){
	this->_ideas[i] = ideas[i];
}