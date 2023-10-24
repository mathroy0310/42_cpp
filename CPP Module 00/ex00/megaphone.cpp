/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   megaphone.cpp                                     ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:05:30 by maroy                                    */
/*   Updated: 2023/10/24 16:16:02 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;

int main (int argc, char **argv)
{
	if (argc == 1) {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (0);
	}
	else if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			for (size_t j = 0; j < strlen(argv[i]); j++) {
				isalpha(argv[i][j]) == 0 ? cout << argv[i][j] : cout << (char)toupper(argv[i][j]);
			}
		}
		cout << endl;
	}
	return (0);
}

