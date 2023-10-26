/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   common.hpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:33:48 by maroy                                    */
/*   Updated: 2023/10/24 16:16:22 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef COMMON_H
# define COMMON_H

// #=- Colors -=# //
# define BOLD "\033[1;37m"
# define NORMAL "\033[0;37m"
# define GREEN "\033[1;92m"
# define GRAY "\033[1;90m"
# define RED "\033[0;31m"
# define YELLOW "\033[1;93m"

// #=- STD Includes -=# //
# include <iomanip>
# include <iostream>

// #=- Namespace Declarations -=# //
using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::getline;
using std::setfill;
using std::setw;
using std::string;

// #=- Local Includes -=# //
# include "Contact.hpp"
# include "PhoneBook.hpp"

// #=- Prototypes -=# //

string	get_input(string msg);
bool	is_valid_index(string input, int max_index);

#endif // COMMON_H