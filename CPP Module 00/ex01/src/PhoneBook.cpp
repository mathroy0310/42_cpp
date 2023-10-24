/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   PhoneBook.cpp                                     ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/09/02 20:06:00 by maroy                                    */
/*   Updated: 2023/10/24 16:29:27 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"
# include "../inc/PhoneBook.hpp"
# include "../inc/Contact.hpp"

const int MAX_CONTACTS = 8;

PhoneBook::PhoneBook (): _index(0){}

PhoneBook::~PhoneBook(){}

void PhoneBook::add_info() {
    if (this->index >= MAX_CONTACTS) {
        cout << YELLOW << " WARNING! Overwriting info about the first contact" << NORMAL << endl;
    }

    int contact_index = this->index % MAX_CONTACTS;
    Contact contact;

    cout << GRAY << "#-- Adding a new contact -- #" << NORMAL << endl;
    contact.set_first_name(get_input("Enter a first name: "));
    contact.set_last_name(get_input("Enter " + contact.get_first_name() + "'s last name: "));
    contact.set_nick_name(get_input("Enter " + contact.get_first_name() + "'s nick name: "));
    contact.set_phone_number(get_input("Enter " + contact.get_first_name() + "'s phone number: "));
    contact.set_darkest_secret(get_input("Enter " + contact.get_first_name() + "'s darkest secret: "));

    contact.truncate_fields_to_limit(10);

    this->_contacts[contact_index] = contact;

    cout << GREEN << "#-- Successfully added to the PhoneBook [" << contact_index + 1 << "/" << MAX_CONTACTS << "] --#" << NORMAL << endl;
    this->_index++;
}


void PhoneBook::print_info()
{
	if (this->_index == 0) {
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
	for (int i = 0; i < this->_index; i++)
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
	if (is_valid_index(input, this->_index))
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