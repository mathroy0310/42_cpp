/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:41:59 by maroy             #+#    #+#             */
/*   Updated: 2023/10/24 22:12:53 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DOG_H
#define DOG_H

#include "Animal.class.hpp"
#include "common.hpp"

class Dog : public Animal
{

public:
	Dog();
	Dog(Dog const &src);
	~Dog();

	Dog &operator=(Dog const &src);

	void makeSound() const;

private:
	string _type;
};

#endif // DOG_H