/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   PhoneBook.cpp                                     ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:06:00 by maroy                                    */
/*   Updated: 2023/10/13 16:23:30 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"
# include "../inc/PhoneBook.hpp"
# include "../inc/Contact.hpp"

PhoneBook::PhoneBook (){
    this->index = 0;
}

PhoneBook::~PhoneBook()
{}

void PhoneBook::add_info()
{
	int contact_index;
	string input;
	string name;
	input = "";

	cout << GRAY << "#-- Adding a new contact -- #" << NORMAL << endl;
	
	if (this->index > 7)
		cout << YELLOW << " WARNING ! Overwriting info about the first contact" << NORMAL << endl;
	contact_index = this->index % 8;
	input = get_input("Enter a first name : ");
    this->_contacts[contact_index].set_first_name(input);;
    input = get_input("Enter " + this->_contacts[contact_index].get_first_name() + "'s last name : ");
	this->_contacts[contact_index].set_last_name(input);
	input = get_input("Enter " + this->_contacts[contact_index].get_first_name() + "'s nick name : ");
	this->_contacts[contact_index].set_nick_name(input);
	input = get_input("Enter " + this->_contacts[contact_index].get_first_name() + "'s phone number : ");
	this->_contacts[contact_index].set_phone_number(input);
	input = get_input("Enter " + this->_contacts[contact_index].get_first_name() + "'s darkest secret : ");
	this->_contacts[contact_index].set_darkest_secret(input);
	if(this->_contacts[contact_index].get_first_name().length() > 10)
		this->_contacts[contact_index].set_first_name(this->_contacts[contact_index].get_first_name().substr(0, 9) + ".");
	if(this->_contacts[contact_index].get_last_name().length() > 10)
		this->_contacts[contact_index].set_last_name(this->_contacts[contact_index].get_last_name().substr(0, 9) + ".");
	if(this->_contacts[contact_index].get_nick_name().length() > 10)
		this->_contacts[contact_index].set_nick_name(this->_contacts[contact_index].get_nick_name().substr(0, 9) + ".");
	if(this->_contacts[contact_index].get_darkest_secret().length() > 10)
		this->_contacts[contact_index].set_darkest_secret(this->_contacts[contact_index].get_darkest_secret().substr(0, 9) + ".");
	cout << GREEN << "#-- Successfully added to the PhoneBook [" << contact_index + 1  << "/8] --#" << NORMAL << endl;
	this->index++;
}


void PhoneBook::print_info()
{
	if (this->index == 0) {
		cout << RED " Nothing to show : use ADD to add a contact" << NORMAL << endl;
		return ;
	}
	cout << GRAY << "#############################################"<< endl;
	cout << "#";
	cout << setw(10) << "Index" << "|";
	cout << setw(10) << "First Name" << "|";
	cout << setw(10) << "Last Name" << "|";
	cout << setw(10) << "Nickname" << "|" << endl;;
	cout << "#############################################"<< NORMAL << endl;
	for (int i = 0; i < this->index; i++)
	{
		cout << GRAY << "|         " << NORMAL << i + 1 << GRAY << "|" << NORMAL;
		cout << setfill (' ') << setw(10) << this->_contacts[i].get_first_name().substr(0, 10) << GRAY << "|" << NORMAL;
		cout << setfill (' ') << setw(10) << this->_contacts[i].get_last_name().substr(0, 10)  << GRAY << "|" << NORMAL;
		cout << setfill (' ') << setw(10) << this->_contacts[i].get_nick_name().substr(0, 10)  << GRAY << "|" << NORMAL << endl;
		cout << GRAY << "---------------------------------------------"<< NORMAL <<endl;
	}
	this->search_info();
}

void PhoneBook::search_info(){
	string input;
	int search_index;
	input = get_input("Enter desired Contact Index : ");
	if (is_valid_index(input, this->index))
	{
		search_index = atoi(input.c_str());
		
		cout << GRAY << "#-- Desired contact info -- #" << NORMAL << endl;
		cout << BOLD << "---------------------------------------------"<< NORMAL << endl;
		cout << BOLD << "|         " << NORMAL << search_index << BOLD << "|" << NORMAL;
		cout << setfill (' ') << setw(10) << this->_contacts[search_index - 1].get_first_name().substr(0, 10) << BOLD << "|" << NORMAL;
		cout << setfill (' ') << setw(10) << this->_contacts[search_index - 1].get_last_name().substr(0, 10)  << BOLD << "|" << NORMAL;
		cout << setfill (' ') << setw(10) << this->_contacts[search_index - 1].get_nick_name().substr(0, 10)  << BOLD << "|" << NORMAL << endl;
		cout << BOLD << "---------------------------------------------"<< NORMAL << endl;
	}
	else
		cout << RED << " Invalid index" << NORMAL << endl;
}