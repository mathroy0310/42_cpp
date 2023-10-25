/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:41:59 by maroy             #+#    #+#             */
/*   Updated: 2023/10/24 21:58:15 by maroy            ###   ########.fr       */
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
	Dog(Dog const &src);
	~Dog();

	Dog &operator=(Dog const &src);

	void makeSound() const;
	Brain *getBrain(void) const;
	void compareTo(Dog const &other_dog) const;

private:
	string _type;
	Brain *_brain;
};

#endif // DOG_H