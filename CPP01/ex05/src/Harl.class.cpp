/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Harl.class.cpp                                    ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 19:35:41 by maroy                                    */
/*   Updated: 2023/11/02 16:12:04 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Harl.class.hpp"
#include "common.hpp"

enum	level_enum
{
	Debug,
	Info,
	Warning,
	Error,
	Other
};

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	cout << DEBUG << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << endl;
}

void Harl::info(void)
{
	cout << INFO << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << endl;
}

void Harl::warning(void)
{
	cout << WARNING << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << endl;
}

void Harl::error(void)
{
	cout << ERROR << "This is unacceptable ! I want to speak to the manager now." << endl;
}

void Harl::complain(string level)
{
	Harl::level_pointer[Debug] = &Harl::debug;
	Harl::level_pointer[Info] = &Harl::info;
	Harl::level_pointer[Warning] = &Harl::warning;
	Harl::level_pointer[Error] = &Harl::error;

	string level_data[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++)
		if (level == level_data[i])
			(this->*level_pointer[i])();
	return ;
}