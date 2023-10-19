/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   ClapTrap.hpp                                      ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 12:11:08 by maroy                                    */
/*   Updated: 2023/10/19 15:06:10 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTAP_H
# define CLAPTAP_H

#include "common.hpp"

class ClapTrap{
	
	public:
		ClapTrap();
		ClapTrap( string name );
		ClapTrap( string name , unsigned int hit_points , unsigned int energy_points , unsigned int attack_damage);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &	operator=( ClapTrap const & rhs );

		// Getters
		string			getName( void ) const;
		unsigned int	getHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getMeleeAttackDamage( void ) const;

		// Setters
		void			setName( string name );
		void			setHitPoints( unsigned int hit_points );
		void			setEnergyPoints( unsigned int energy_points );
		void			setMeleeAttackDamage( unsigned int attack_damage );

		// Member functions
		bool			isAlive( void );
		bool			isEnergy( void );
		void			printStatus( void );
		void			attack( string const & target );
		void			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );
		
	
	protected:
		string 			_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
		
	
};

#endif // CLAPTAP_HP
