/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   HumanA.class.hpp                                  ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 18:20:34 by maroy                                    */
/*   Updated: 2023/11/02 15:25:44 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#include "Weapon.class.hpp"
#include "common.hpp"

class HumanA
{
  public:
	HumanA(string name, Weapon &weapon);
	~HumanA();

	// #=- Getters -=# //

	string getName(void);
	Weapon *getWeapon(void);

	// #=- Setters -=# //

	void setName(string name);
	void setWeapon(Weapon &weapon);

	// #=- Actions -=# //

	void attack(void);

  private:
	string _name;
	Weapon *_weapon;
};