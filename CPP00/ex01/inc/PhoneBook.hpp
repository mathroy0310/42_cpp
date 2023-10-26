/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   PhoneBook.hpp                                     ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:05:38 by maroy                                    */
/*   Updated: 2023/10/24 16:28:11 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "common.hpp"
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
		~PhoneBook();
		void add_info();
		void print_info();
		void search_info();
    private:
        Contact _contacts[8];
        int 	_index;
};

#endif /* PHONEBOOK_HPP */