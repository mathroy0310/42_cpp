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
    this->_ideas = new string[100];
    for (int i = 0; i < 100; i++)
    {
		if (ref.getIdea(i) == "")
			break;
		this->_ideas[i] = ref._ideas[i] + " (copied)";
    }
}

Brain::~Brain()
{
    cout << "Brain destructor called" << endl;
    if (this->_ideas)
        delete[] this->_ideas;
}

///////////////////////////
///		OPERATORS		///
///////////////////////////

Brain &
Brain::operator=(Brain const &rhs)
{
    for (int i = 0; i < 100; i++)
    {
        if (this->getIdea(i) == "")
        {
            this->_ideas[i] = rhs._ideas[i];
			return (*this);
        }
    }
    return (*this);
}

///////////////////////////
///	Setters & Getters	///
///////////////////////////

string
Brain::getIdea(unsigned int i) const
{
    if (i > 99)
    {
        cout << "Can't get idea " << i << ". Index out of range!" << endl;
        return "";
    }
    return (this->_ideas[i]);
}

void
Brain::setIdea(unsigned int i, string ideas)
{
    if (i > 99)
    {
        cout << "Can't set idea " << i << ". Index out of range!" << endl;
        return;
    }
    this->_ideas[i] = ideas;
}