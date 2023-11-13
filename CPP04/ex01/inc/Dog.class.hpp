/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:41:59 by maroy             #+#    #+#             */
/*   Updated: 2023/11/13 18:05:54 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DOG_H
#define DOG_H

#include "Animal.class.hpp"
#include "Brain.class.hpp"
#include "common.hpp"

class Dog : public Animal
{
  public:
    Dog();
    Dog(Dog &ref);
    ~Dog();

    Dog &operator=(Dog const &src);

    void   makeSound() const;
    void   giveIdea(string idea);
    Brain *getBrain(void) const;
    void   printIdeas(void) const;
    bool   isAbstract() const;

  private:
    string _type;
    Brain *_brain;
};

#endif // DOG_H