/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Weapon.hpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 18:16:47 by maroy                                    */
/*   Updated: 2023/10/14 18:29:38 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_H
# define WEAPON_H

#include "common.hpp"

class Weapon
{

	public:

		Weapon(string type);
		~Weapon();

		// #=- Getters -=# //
		string		getType(void);
		// #=- Setters -=# //
		void			setType(string type);

	private:

		string		_type;

};

#endif // WEAPON_H