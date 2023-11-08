/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   ScavTrap.class.hpp                                ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 13:30:26 by maroy                                    */
/*   Updated: 2023/11/08 16:51:17 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.class.hpp"
#include "common.hpp"


class ScavTrap: public ClapTrap{
	
	public:
		ScavTrap();
		ScavTrap( string name );
		ScavTrap( ScavTrap const & src );
		~ScavTrap();

		void 			attack( string const & target );
		void			guardGate( void );
};

# endif