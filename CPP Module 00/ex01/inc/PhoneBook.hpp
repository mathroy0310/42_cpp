/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   PhoneBook.hpp                                     ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:05:38 by maroy                                    */
/*   Updated: 2023/10/13 16:37:45 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

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
        int index;
};
