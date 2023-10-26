/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:05:50 by maroy                                    */
/*   Updated: 2023/10/26 18:03:29 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "common.hpp"
#include "PhoneBook.class.hpp"

// #=- Main Program -=# //

int	main(void)
{
	string input;
	PhoneBook my_phone_book;

	cout << YELLOW << " == Welcome To MyPhoneBook == " << NORMAL << endl;
	while (1)
	{
		cout << BOLD << "Enter a command : " << NORMAL;
		getline(cin, input);
		if (cin.eof()) /* <-- Ctrl + D */
			exit(0);
		if (input == "ADD")
			my_phone_book.add_info();
		else if (input == "EXIT")
		{
			cout << GRAY << "Exiting..." << NORMAL << endl;
			exit(0);
		}
		else if (input == "SEARCH")
			my_phone_book.print_info();
		else if (input == "HELP")
			cout << GRAY << "Commands: ADD, SEARCH, EXIT, HELP" << NORMAL << endl;
		else
			cout << RED << " Invalid command" << NORMAL << endl;
	}
	return (0);
}