/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:40:05 by maroy             #+#    #+#             */
/*   Updated: 2023/11/13 18:16:47 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "AAnimal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "common.hpp"

int
main(void)
{
    {
        cout << ANSI_COLOR_BOLD << "proof Abstract Class" << ANSI_COLOR_RESET
             << endl;
        cout << std::setfill('-') << std::setw(64) << "-" << endl;
        const AAnimal *meta = new Dog();
        // AAnimal *meta = new AAnimal(); // pas compile pske classe abstraite
        if (meta->isAbstract())
            cout << ANSI_COLOR_BRIGHT_GREEN << "AAnimal is abstract";
        else
            cout << ANSI_COLOR_BRIGHT_RED << "AAnimal is not abstract";
        cout << ANSI_COLOR_RESET << endl;
        meta->makeSound();

        delete meta;
    }
    cout << endl;
    {
        cout << ANSI_COLOR_BOLD << "AAnimal , Dog, Cat" << ANSI_COLOR_RESET
             << endl;
        cout << std::setfill('-') << std::setw(64) << "-" << endl;
        // const AAnimal *meta = new AAnimal();
        const AAnimal *dog = new Dog();
        const AAnimal *cat = new Cat();
        cout << "Type :" << dog->getType() << endl;
        dog->makeSound(); // output le son du chien!
        cout << "Type :" << cat->getType() << endl;
        cat->makeSound(); // output le son du chat!
        // cout << "Type :" << meta->getType() << endl;
        // meta->makeSound();

        // delete meta;
        delete dog;
        delete cat;
    }
    cout << endl;
    {
        cout << ANSI_COLOR_BOLD << "Deep Copy preuve" << ANSI_COLOR_RESET
             << endl;
        cout << std::setfill('-') << std::setw(64) << "-" << endl;
        Cat *minou = new Cat();

        cout << endl;

        minou->giveIdea("du lait");
        minou->giveIdea("poisson miam");
        minou->giveIdea("miaou");
        minou->giveIdea("bouffe jsp");
        minou->printIdeas();

        cout << endl;

        Cat *chaton = new Cat(*minou);

        cout << endl;

        chaton->giveIdea("dodo zzz");
        chaton->printIdeas();
        cout << endl;

        delete minou;
        delete chaton;

        cout << endl;

        Dog *ptichien = new Dog();

        cout << endl;

        ptichien->giveIdea("balle");
        ptichien->giveIdea("os");
        ptichien->giveIdea("bouffe");
        ptichien->giveIdea("parc");
        ptichien->printIdeas();

        cout << endl;

        Dog *chiot = new Dog(*ptichien);

        cout << endl;

        chiot->giveIdea("dodo zzz");
        chiot->printIdeas();
        cout << endl;

        delete ptichien;
        delete chiot;
    }
    cout << endl;
    {
        // Array of animals
        cout << ANSI_COLOR_BOLD << "AAnimal Array" << ANSI_COLOR_RESET << endl;
        cout << std::setfill('-') << std::setw(64) << "-" << endl;
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

        cout << "AAnimal array sounds:" << endl;
        for (int i = 0; i < 4; i++)
            animal_array[i]->makeSound();

        for (int i = 0; i < 4; i++)
            delete animal_array[i];
        cout << endl;
    }
    cout << endl;
    {
        cout << ANSI_COLOR_BOLD << "Copy Assingment operator"
             << ANSI_COLOR_RESET << endl;
        cout << std::setfill('-') << std::setw(64) << "-" << endl;
        Cat *minou = new Cat();
        cout << endl;

        Cat *chaton = new Cat();
        cout << endl;

        minou->giveIdea("du lait");
        minou->giveIdea("pas dodo");
        *chaton = *minou;
        cout << endl;
        cout << "minou :";
        minou->printIdeas();
        cout << "chaton :";
        chaton->printIdeas();

        delete minou;
        delete chaton;

        Dog *ptichien = new Dog();
        cout << endl;

        Dog *chiot = new Dog();
        cout << endl;

        ptichien->giveIdea("du lait");
        ptichien->giveIdea("pas dodo");
        *chiot = *ptichien;
        cout << endl;
        cout << "ptichien :";
        ptichien->printIdeas();
        cout << "chiot :";
        chiot->printIdeas();

        delete ptichien;
        delete chiot;
    }
    return (0);
}