/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   megaphone.cpp                                     ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:05:30 by maroy                                    */
/*   Updated: 2023/09/02 20:05:33 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include <iostream>

int main (int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	else if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			for (size_t j = 0; j < strlen(argv[i]); j++) {
				isalpha(argv[i][j]) == 0 ? std::cout << argv[i][j] : std::cout << (char)toupper(argv[i][j]);
			}
		}
		std::cout << std::endl;
	}
	return 0;
}

