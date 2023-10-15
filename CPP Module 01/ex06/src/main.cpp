/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 19:35:34 by maroy                                    */
/*   Updated: 2023/10/14 20:31:27 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main (int argc , char **argv)
{
	if (argc != 2)
	{
		std::cout << ANSI_COLOR_RED"Error 🛑: Usage:  "<< argv[0] <<" [DEBUG|INFO|WARNING|ERROR]" << std::endl;
		return (EXIT_FAILURE);
	}
	Harl harl;
	harl.complain( argv[1] );

	return (EXIT_SUCCESS);
}