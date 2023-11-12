/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:40:05 by maroy                                    */
/*   Updated: 2023/11/11 14:14:10 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "common.hpp"
#include <iomanip>

#include "Animal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int main()
{
	{
		cout << ANSI_COLOR_BOLD <<"ANimal , Dog, Cat" << ANSI_COLOR_RESET << endl;
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
	std::cout << std::endl;
	{
		cout << ANSI_COLOR_BOLD << "WrongANimal , WrongCat" << ANSI_COLOR_RESET  << endl;
		cout << std::setfill('-') << std::setw(64) << "-" << endl;
		const WrongAnimal *wrongMeta = new WrongAnimal();
		const WrongAnimal *wrongCat = new WrongCat();
		std::cout << wrongCat->getType() << " " << std::endl;
		wrongCat->makeSound();
		wrongMeta->makeSound();

		delete wrongMeta;
		delete wrongCat;
	}
	return EXIT_SUCCESS;
}