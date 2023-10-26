/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   common.hpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:33:48 by maroy                                    */
/*   Updated: 2023/10/26 19:14:32 by maroy            >(.)__ <(.)__ =(.)__    */
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
using std::left;

// #=- Prototypes -=# //

string	get_input(string msg);
bool	is_valid_index(string input, int max_index);
string truncate_to_limits(string input , size_t limit);

#endif // COMMON_H