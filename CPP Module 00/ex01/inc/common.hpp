/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   common.hpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:33:48 by maroy                                    */
/*   Updated: 2023/10/13 16:37:23 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

// #=- Colors -=# //
# define BOLD "\033[1;37m"
# define NORMAL "\033[0;37m"
# define GREEN "\033[1;92m"
# define GRAY "\033[1;90m"
# define RED "\033[0;31m"
# define YELLOW "\033[1;93m"

// #=- STD Includes -=# //
#include <iostream>
#include <iomanip>

// #=- Namespace Declarations -=# //
using std::cout;
using std::cin;
using std::getline;
using std::end;
using std::begin;
using std::endl;
using std::string;
using std::setw;
using std::setfill;

// #=- Local Includes -=# //
#include "PhoneBook.hpp"
#include "Contact.hpp"

// #=- Prototypes -=# //

/// @brief get the input from the user with getline
/// @param msg the message the before reading the user input 
/// @return return the input as string
string	get_input(string msg);
/// @brief Checks if the index user input is valid or not 
/// @param input the input as string from the user
/// @param max_index the number of contacts in the phonebook
/// @return true or false , valid or not
bool	is_valid_index(string input, int max_index);