/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Cat.class.hpp                                     ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:42:40 by maroy                                    */
/*   Updated: 2023/11/11 16:42:17 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
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
	Cat(Cat const &src);
	~Cat();

	Cat &operator=(Cat const &src);

	void makeSound() const;
	Brain *getBrain(void) const;
	void giveIdea(string idea);
	void takeIdea(void) const;
private:
	string _type;
	Brain *_brain;
};

#endif // CAT_H