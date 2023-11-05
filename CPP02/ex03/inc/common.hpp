/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   common.hpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 16:54:43 by maroy                                    */
/*   Updated: 2023/11/05 16:25:52 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once
#ifndef COMMON_H
# define COMMON_H

// #ifndef DEBUG
// # define DEBUG 0
// #endif

// #=- Colors -=# //
# define ANSI_COLOR_RESET "\x1b[0m"
# define ANSI_COLOR_BLACK "\x1b[30m"
# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define ANSI_COLOR_WHITE "\x1b[37m"
# define ANSI_COLOR_BRIGHT_BLACK "\x1b[30;1m"
# define ANSI_COLOR_BRIGHT_RED "\x1b[31;1m"
# define ANSI_COLOR_BRIGHT_GREEN "\x1b[32;1m"
# define ANSI_COLOR_BRIGHT_YELLOW "\x1b[33;1m"
# define ANSI_COLOR_BRIGHT_BLUE "\x1b[34;1m"
# define ANSI_COLOR_BRIGHT_MAGENTA "\x1b[35;1m"
# define ANSI_COLOR_BRIGHT_CYAN "\x1b[36;1m"
# define ANSI_COLOR_BRIGHT_WHITE "\x1b[37;1m"
# define ANSI_COLOR_BOLD "\033[1;37m"

// #=- STD Includes -=# //
# include <cmath>
# include <iostream>
# include <string>

// #=- Namespace Declarations -=# //
using std::cerr;
using std::cout;
using std::endl;
using std::ostream;
using std::string;

# include "Fixed.class.hpp"
# include "Point.class.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif // COMMON_H