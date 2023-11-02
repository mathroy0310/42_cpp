/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Weapon.class.hpp                                  ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 18:16:47 by maroy                                    */
/*   Updated: 2023/11/02 16:28:23 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once
#include "common.hpp"

class Weapon
{

	public:

		Weapon(string type);
		~Weapon();

		// #=- Getters -=# //
		//reference to a const string
		const string& 	getType(void) const;
		// #=- Setters -=# //
		void			setType(string type);

	private:

		string		_type;

};