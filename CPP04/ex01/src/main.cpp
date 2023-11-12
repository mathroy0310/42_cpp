/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:40:05 by maroy                                    */
/*   Updated: 2023/11/11 17:10:05 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include <iomanip>
#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "common.hpp"

int main(void)
{
	{
		cout << ANSI_COLOR_BOLD << "Animal , Dog, Cat" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		j->makeSound(); // output le son du chien!
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // output le son du chat!
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	cout << endl;
	{
		cout << ANSI_COLOR_BOLD << "Deep Copy proof" << ANSI_COLOR_RESET  << endl;
		Dog dogo;
		Cat minou;

		for (size_t i = 0; i < 100; i++)
		{
			dogo.getBrain()->setIdea(i, "Idea " + std::to_string(i));
		}
		dogo.printIdeas();
	}
	cout << endl;
	{
		// Array of animals
		cout << ANSI_COLOR_BOLD << "Animal Array" << ANSI_COLOR_RESET << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		const Animal *animal_array[4];
		cout << endl;
		// Half filled with dogs
		for (int i = 0; i < 2; i++)
			animal_array[i] = new Dog();
		cout << endl;

		// Half filled with cats
		for (int i = 2; i < 4; i++)
			animal_array[i] = new Cat();
		cout << endl;

		cout << "Animal array sounds:" << endl;
		for (int i = 0; i < 4; i++)
			animal_array[i]->makeSound();

		for (int i = 0; i < 4; i++)
			delete animal_array[i];
		cout << endl;
		
	}
	return (0);
}