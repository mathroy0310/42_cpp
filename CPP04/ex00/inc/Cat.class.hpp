/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Cat.class.hpp                                     ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:42:40 by maroy                                    */
/*   Updated: 2023/11/11 13:22:45 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef CAT_H
#define CAT_H

#include "common.hpp"
#include "Animal.class.hpp"

class Cat : public Animal
{

public:
	Cat();
	Cat(Cat const &src);
	~Cat();

	Cat &operator=(Cat const &src);

	void makeSound() const;

private:
	string _type;
};

#endif // CAT_H