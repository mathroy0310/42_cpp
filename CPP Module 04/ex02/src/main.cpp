/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:40:05 by maroy             #+#    #+#             */
/*   Updated: 2023/10/24 22:21:06 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "common.hpp"

int main(void)
{
	const AAnimal *dog = new Dog();
	const AAnimal *cat = new Cat();
	cout << dog->getType() << " " << endl;
	cout << cat->getType() << " " << endl;
	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	cout << endl
		 << "---------------------" << endl;
	cout << "Proof Deep copy";
	cout << endl
		 << "---------------------" << endl;

	Dog dogo;
	Cat minou;

	Dog &dogo_ref = dogo;
	Cat &minou_ref = minou;

	cout << endl
		 << "creating copies" << endl;
	Dog dogo_copy(dogo_ref);
	Cat minou_copy(minou_ref);

	Dog &dogo_copy_ref = dogo_copy;
	Cat &minou_copy_ref = minou_copy;

	cout << endl
		 << "comparing" << endl;
	dogo.compareTo(dogo_copy_ref);
	minou.compareTo(minou_copy_ref);
	cout << endl;

	cout << endl
		 << "---------------------" << endl;
	cout << "Iterate animal array";
	cout << endl
		 << "---------------------" << endl;
	// Array of animals
	const AAnimal *animal_array[4];
	cout << endl;
	// Half filled with dogs
	for (int i = 0; i < 2; i++)
		animal_array[i] = new Dog();
	cout << endl;

	// Half filled with cats
	for (int i = 2; i < 4; i++)
		animal_array[i] = new Cat();
	cout << endl;

	for (int i = 0; i < 4; i++)
		delete animal_array[i];
	cout << endl;
	return (0);
}