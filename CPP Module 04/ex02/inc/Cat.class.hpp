/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:42:40 by maroy             #+#    #+#             */
/*   Updated: 2023/10/24 22:19:42 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_H
#define CAT_H

#include "AAnimal.class.hpp"
#include "Brain.class.hpp"
#include "common.hpp"

class Cat : public AAnimal
{
public:
	Cat();
	Cat(Cat const &src);
	~Cat();

	Cat &operator=(Cat const &src);

	void makeSound() const;
	Brain *getBrain(void) const;
	void compareTo(Cat const &other_cat) const;

private:
	string _type;
	Brain *_brain;
};

#endif // CAT_H