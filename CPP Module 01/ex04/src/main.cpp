/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 18:51:31 by maroy                                    */
/*   Updated: 2023/10/14 19:27:08 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		cerr << ERR_PREFIX"Invalid number of arguments."<< endl;
		cerr <<"Usage: ./" << argv[0] << " <filename> <string1> <string2>"<< ANSI_COLOR_RESET  << endl;
		return EXIT_FAILURE;
	}
	
	string filename = argv[1];
	ifstream infile;
	infile.open(filename);
	if (infile.fail())
	{
		cerr << ERR_PREFIX"File does not exist.\"" << filename << "\"" << ANSI_COLOR_RESET << endl;
		return EXIT_FAILURE;
	}
	
	string new_filename = filename + ".replace";
	ofstream outfile(new_filename);
	if (outfile.fail())
	{
		cerr << ERR_PREFIX"Failed to create file. \"" << new_filename << "\"" << ANSI_COLOR_RESET << endl;
		return EXIT_FAILURE;
	}
	
	string line;
	string s1 = 	argv[2];
	string s2 = 	argv[3];
    while (getline(infile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != string::npos) {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outfile << line << "\n";
    }
	cout << SUCCESS_PREFIX"The file has been processed successfully. The result has been written to " << filename << ".replace" << ANSI_COLOR_RESET << endl;
	
	infile.close();
	outfile.close();
	
	return EXIT_SUCCESS;
}