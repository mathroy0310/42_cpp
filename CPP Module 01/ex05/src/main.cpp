/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 19:35:34 by maroy                                    */
/*   Updated: 2023/10/14 19:57:31 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main ( void )
{
	Harl harl;

	harl.complain( "DEBUG" );
	harl.complain( "INFO" );
	harl.complain( "WARNING" );
	harl.complain( "ERROR" );
	harl.complain( "test" );
	harl.complain( "DEBUG" );

	return (EXIT_SUCCESS);
}