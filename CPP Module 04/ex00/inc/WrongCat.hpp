/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   WrongCat.hpp                                      ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 19:26:10 by maroy                                    */
/*   Updated: 2023/10/20 19:37:19 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "common.hpp"
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	
	public: 
		WrongCat();
		WrongCat(WrongCat const & src);
		~WrongCat();

		WrongCat & operator=(WrongCat const & src);

		void	makeSound() const;
};

#endif // WRONGCAT_H