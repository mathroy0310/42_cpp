/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 17:57:03 by maroy                                    */
/*   Updated: 2023/10/26 13:55:03 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "common.hpp"

int	main(void)
{
	string str = "HI THIS IS BRAIN";
	string *stringPTR = &str;
	string &stringREF = str;

	cout << setfill('-') << setw(52) << "-" << endl;
	cout << setfill(' ') << left << setw(32) << "string address:" << &str << endl;
	cout << setfill(' ') << left << setw(32) << "stringPTR address:" << stringPTR << endl;
	cout << setfill(' ') << left << setw(32) << "stringREF address:" << &stringREF << endl;
	cout << setfill('-') << setw(52) << "-" << endl;
	cout << setfill(' ') << left << setw(32) << "string value:" << str << endl;
	cout << setfill(' ') << left << setw(32) << "stringPTR value:" << *stringPTR << endl;
	cout << setfill(' ') << left << setw(32) << "stringREF value:" << stringREF << endl;
	cout << setfill('-') << setw(52) << "-" << endl;

	return (EXIT_SUCCESS);
}