/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   HumanA.hpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 18:20:34 by maroy                                    */
/*   Updated: 2023/10/14 18:40:37 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_H
# define HUMANA_H

#include "common.hpp"
#include "Weapon.hpp"

class HumanA
{
	public:

		HumanA(string name, Weapon &weapon);
		~HumanA();

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

#endif // HUMANA_H