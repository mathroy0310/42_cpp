/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Dog.hpp                                           ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:41:59 by maroy                                    */
/*   Updated: 2023/10/24 15:32:08 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "common.hpp"

class Dog : public Animal
{
  public:
	Dog();
	Dog(Dog const &src);
	~Dog();

	Dog &operator=(Dog const &src);

	void makeSound() const;

};

#endif // DOG_H