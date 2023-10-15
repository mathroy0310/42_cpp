/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   utils.cpp                                         ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 16:59:24 by maroy                                    */
/*   Updated: 2023/10/14 17:03:37 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"

string	get_input(string msg){
	string input;
	
	input = "";
	while (!cin.eof() && input == "") {
		cout << BOLD << msg << NORMAL;
		if (getline(cin, input) && input != "")
			return (input);
	}
	exit(1);
}


bool	is_valid_index(string input, int max_index){

	int search_index = atoi(input.c_str());
	return (all_of(input.begin(), input.end(), ::isdigit) && (search_index <= max_index && search_index >= 0));
}