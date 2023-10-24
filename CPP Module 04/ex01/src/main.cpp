/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:40:05 by maroy                                    */
/*   Updated: 2023/10/24 15:40:00 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "common.hpp"

int	
main
(void)
{
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();

	delete meta; delete dog; delete cat;

	cout << endl << "---------------------" << endl;
	cout << "Iterate animal array";
	cout << endl << "---------------------" << endl;
	Animal *animals[10];
	for (int i = 0; i < 5; i++){
		animals[i] = new Cat();
		animals[i]->makeSound();
	}
	for (int i = 5; i < 10; i++){
		animals[i] = new Dog();
		animals[i]->makeSound();
	}
	string ideas[100];
	for (size_t i = 0; i < 100; i++)
	{
		ideas[i] = "idea" + std::to_string(i);	
		animals[i]->_brain->setIdeas(i, ideas);
	}
	
	
	for (int i = 0; i < 10; i++){
		delete animals[i];}

	return (0);
}