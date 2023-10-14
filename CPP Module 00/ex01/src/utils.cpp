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