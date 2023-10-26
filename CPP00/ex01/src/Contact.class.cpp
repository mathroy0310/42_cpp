/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Contact.class.cpp                                 ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:05:25 by maroy                                    */
/*   Updated: 2023/10/26 13:11:32 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/Contact.hpp"
#include "../inc/common.hpp"

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

//////////////////////////////////////////
//										//
//		MEMBER FONCTIONS				//
//										//
//////////////////////////////////////////

void Contact::truncate_fields_to_limit(size_t limit)
{
	if (this->_first_name.length() > limit)
	{
		this->_first_name = this->_first_name.substr(0, limit - 1) + ".";
	}
	if (this->_last_name.length() > limit)
	{
		this->_last_name = this->_last_name.substr(0, limit - 1) + ".";
	}
	if (this->_nick_name.length() > limit)
	{
		this->_nick_name = this->_nick_name.substr(0, limit - 1) + ".";
	}
	if (this->_darkest_secret.length() > limit)
	{
		this->_darkest_secret = this->_darkest_secret.substr(0, limit - 1)
			+ ".";
	}
}
