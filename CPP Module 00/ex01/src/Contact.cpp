/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Contact.cpp                                       ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:05:25 by maroy                                    */
/*   Updated: 2023/10/13 16:51:49 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

# include "../inc/common.hpp"
# include"../inc/Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

string Contact::Contact::get_first_name(void) const {
	return (this->_first_name);
}

string Contact::Contact::get_last_name(void) const {
	return (this->_last_name);
}

string Contact::Contact::get_nick_name(void) const {
	return (this->_nick_name);
}

string Contact::Contact::get_phone_number(void) const {
	return (this->_phone_number);
}

string Contact::Contact::get_darkest_secret(void) const {
	return (this->_darkest_secret);
}

void Contact::Contact::set_first_name(string first_name){
	this->_first_name = first_name;
}

void Contact::Contact::set_last_name(string last_name){
	this->_last_name = last_name;
}

void Contact::Contact::set_nick_name(string nick_name){
	this->_nick_name = nick_name;
}

void Contact::Contact::set_phone_number(string phone_number){
	this->_phone_number = phone_number;
}

void Contact::Contact::set_darkest_secret(string darkest_secret){
	this->_darkest_secret = darkest_secret;
}