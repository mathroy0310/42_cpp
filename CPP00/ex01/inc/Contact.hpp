/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Contact.hpp                                       ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:05:35 by maroy                                    */
/*   Updated: 2023/10/24 16:26:28 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_HPP
# define CONTACT_HPP


#include "common.hpp"
#include <iostream>

class Contact
{
    public:
        Contact();
		//Destructor
        ~Contact();
		//Getters
		string get_first_name(void) const ;
		string get_last_name(void) const ;
		string get_nick_name(void) const ;
		string get_phone_number(void) const ;
		string get_darkest_secret(void) const ;
		//Setters
		void set_first_name(string first_name);
		void set_last_name(string last_name);
		void set_nick_name(string nick_name);
		void set_phone_number(string phone_number);
		void set_darkest_secret(string darkest_secret);

		//Member fonctions
		void truncate_fields_to_limit(size_t limit);
    private:
        string _first_name;
        string _last_name;
        string _nick_name;
        string _phone_number;
        string _darkest_secret;
};

#endif /* CONTACT_HPP */