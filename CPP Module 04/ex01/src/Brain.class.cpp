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
	// cout << "Brain default constructor called" << endl;
	this->_ideas = new string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Ricard...";
}

Brain::Brain(Brain &ref)
{
	string *ref_ideas = ref.getIdeas();
	this->_ideas = new string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ref_ideas[i] + " stolen";
}

Brain::~Brain()
{
	// cout << "Brain destructor called" << endl;
	delete[] (this->_ideas);
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

string *Brain::getIdeas(void)
{
	return (this->_ideas);
}

void Brain::setIdeas(int i, string *ideas)
{
	this->_ideas[i] = ideas[i];
}