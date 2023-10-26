/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:42:43 by maroy             #+#    #+#             */
/*   Updated: 2023/10/24 21:53:22 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AANIMAL_H
#define AANIMAL_H

#include "Brain.class.hpp"
#include "common.hpp"

class AAnimal
{
public:
	AAnimal();
	AAnimal(AAnimal const &src);
	virtual ~AAnimal() = 0;

	AAnimal &operator=(AAnimal const &src);

	virtual void makeSound() const = 0;
	// Setters - Getters
	string getType() const;
	void setType(string type);

protected:
	string _type;
};

#endif // AANIMAL_H