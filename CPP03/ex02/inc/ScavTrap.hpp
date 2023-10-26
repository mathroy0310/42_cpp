/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   ScavTrap.hpp                                      ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 13:30:26 by maroy                                    */
/*   Updated: 2023/10/19 15:07:26 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "common.hpp"
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
	
	public:
		ScavTrap();
		ScavTrap( string name );
		ScavTrap( ScavTrap const & src );
		
		~ScavTrap();
		
		void			printStatus( void );
		void 			attack( string const & target );
		void			guardGate( void );
};

#endif // SCAVTRAP_HPP