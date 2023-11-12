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

#include "Brain.class.hpp"

///////////////////////////////////
///	CONSTRUCTORS & DESTRUCTOR	///
///////////////////////////////////

Brain::Brain()
{
	cout << "Brain default constructor called" << endl;
	this->_ideas = new string[100];
}

Brain::Brain(Brain &ref)
{
	cout << "Brain copy constructor called" << endl;
	for (int i = 0; i < 100; i++)
		ref.setIdea(i, (this->_ideas[i] + " copy"));
	
}

Brain::~Brain()
{
	cout << "Brain destructor called" << endl;
	if (this->_ideas)
		delete [] this->_ideas;
}

///////////////////////////
///		OPERATORS		///
///////////////////////////

Brain &Brain::operator=(Brain const &rhs)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

///////////////////////////
///	Setters & Getters	///
///////////////////////////

string Brain::getIdea(int i) const
{
	return (this->_ideas[i]);
}

void Brain::setIdea(int i, string ideas)
{
	this->_ideas[i] = ideas[i];
}