/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:40:05 by maroy             #+#    #+#             */
/*   Updated: 2023/11/13 18:03:51 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"
#include <iomanip>

#include "Animal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int
main()
{
    {
        cout << ANSI_COLOR_BOLD << "ANimal , Dog, Cat" << ANSI_COLOR_RESET
             << endl;
        cout << std::setfill('-') << std::setw(64) << "-" << endl;
        const Animal *meta = new Animal();
        const Animal *dog  = new Dog();
        const Animal *cat  = new Cat();
        cout << "Type :" << dog->getType() << endl;
        dog->makeSound(); // output le son du chien!
        cout << "Type :" << cat->getType() << endl;
        cat->makeSound(); // output le son du chat!
        cout << "Type :" << meta->getType() << endl;
        meta->makeSound();

        delete meta;
        delete dog;
        delete cat;
    }
    cout << endl;
    {
        cout << ANSI_COLOR_BOLD << "WrongANimal , WrongCat" << ANSI_COLOR_RESET
             << endl;
        cout << std::setfill('-') << std::setw(64) << "-" << endl;
        const WrongAnimal *wrongMeta = new WrongAnimal();
        const WrongAnimal *wrongCat  = new WrongCat();
        cout << wrongCat->getType() << " " << endl;
        cout << "Type :" << wrongCat->getType() << endl;
        wrongCat->makeSound();
        cout << "Type :" << wrongMeta->getType() << endl;
        wrongMeta->makeSound();

        delete wrongMeta;
        delete wrongCat;
    }
    return 0;
}