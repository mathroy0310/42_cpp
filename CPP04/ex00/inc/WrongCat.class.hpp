/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:26:10 by maroy             #+#    #+#             */
/*   Updated: 2023/10/24 22:12:51 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "common.hpp"
#include "WrongAnimal.class.hpp"

class WrongCat : public WrongAnimal
{

public:
	WrongCat();
	WrongCat(WrongCat const &src);
	~WrongCat();

	WrongCat &operator=(WrongCat const &src);

	void makeSound() const;

private:
	string _type;
};

#endif // WRONGCAT_H