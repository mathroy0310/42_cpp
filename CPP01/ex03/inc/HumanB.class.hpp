/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   HumanB.class.hpp                                  ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 18:21:13 by maroy                                    */
/*   Updated: 2023/11/02 15:25:51 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#include "common.hpp"
#include "Weapon.class.hpp"

class HumanB 
{	
	public:

		HumanB(string name);
		~HumanB();

		// #=- Getters -=# //
		
		string		getName(void);
		Weapon		*getWeapon(void);

		// #=- Setters -=# //

		void			setName(string name);
		void			setWeapon(Weapon &weapon);

		// #=- Actions -=# //

		void			attack(void);

	private:

		string		_name;
		Weapon		*_weapon;

};