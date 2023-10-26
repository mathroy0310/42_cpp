/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Contact.class.cpp                                 ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:05:25 by maroy                                    */
/*   Updated: 2023/10/26 18:57:57 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "common.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

//////////////////////////////////////////
//										//
//			GETTERS						//
//										//
//////////////////////////////////////////

string Contact::get_first_name(void) const
{
	return (this->_first_name);
}

string Contact::get_last_name(void) const
{
	return (this->_last_name);
}

string Contact::get_nick_name(void) const
{
	return (this->_nick_name);
}

string Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

string Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}

//////////////////////////////////////////
//										//
//			SETTERS						//
//										//
//////////////////////////////////////////

void Contact::set_first_name(string first_name)
{
	this->_first_name = first_name;
}

void Contact::set_last_name(string last_name)
{
	this->_last_name = last_name;
}

void Contact::set_nick_name(string nick_name)
{
	this->_nick_name = nick_name;
}

void Contact::set_phone_number(string phone_number)
{
	this->_phone_number = phone_number;
}

void Contact::set_darkest_secret(string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}
