/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Harl.class.hpp                                    ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 19:33:20 by maroy                                    */
/*   Updated: 2023/10/26 13:47:24 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef HARL_H
# define HARL_H

# include "common.hpp"

class Harl
{
  public:
	Harl();
	~Harl();

	void complain(string level);
	void (Harl::*level_pointer[4])(void);

  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif // HARL_H