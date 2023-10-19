/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   DiamondTrap.hpp                                   ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 16:49:40 by maroy                                    */
/*   Updated: 2023/10/19 17:00:39 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "common.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{

	public:

		DiamondTrap();
		DiamondTrap( string name );
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap();

		DiamondTrap &		operator=( DiamondTrap const & rhs );

		void				whoAmI( void );

	private:
		string name;

};


#endif // DiamondTrap_HPP