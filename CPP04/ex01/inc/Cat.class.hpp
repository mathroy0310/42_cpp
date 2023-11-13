/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:42:40 by maroy             #+#    #+#             */
/*   Updated: 2023/11/13 18:05:51 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_H
#define CAT_H

#include "Animal.class.hpp"
#include "Brain.class.hpp"
#include "common.hpp"

class Cat : public Animal
{
  public:
    Cat();
    Cat(Cat &ref);
    ~Cat();

    Cat &operator=(Cat const &src);

    void   makeSound() const;
    void   giveIdea(string idea);
    Brain *getBrain(void) const;
    void   printIdeas() const;
    bool   isAbstract() const;

  private:
    string _type;
    Brain *_brain;
};

#endif // CAT_H