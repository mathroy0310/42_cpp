/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Cat.hpp                                           ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 18:42:40 by maroy                                    */
/*   Updated: 2023/10/24 15:32:12 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "common.hpp"

class Cat : public Animal
{
  public:
	Cat();
	Cat(Cat const &src);
	~Cat();

	Cat &operator=(Cat const &src);

	void makeSound() const;

};

#endif // CAT_H