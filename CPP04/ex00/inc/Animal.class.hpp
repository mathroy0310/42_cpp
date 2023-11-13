/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:42:43 by maroy             #+#    #+#             */
/*   Updated: 2023/11/13 18:04:04 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_H
#define ANIMAL_H

#include "common.hpp"

class Animal
{
  public:
    Animal();
    Animal(Animal const &src);
    virtual ~Animal();

    Animal &operator=(Animal const &src);

    void   setType(string type);
    string getType(void) const;

    virtual void makeSound(void) const;

  protected:
    string _type;
};

#endif // ANIMAL_H