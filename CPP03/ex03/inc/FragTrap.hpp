/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   FragTrap.hpp                                      ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/19 14:52:04 by maroy                                    */
/*   Updated: 2023/10/19 15:07:23 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP


#include "common.hpp"
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
	
	public:
		FragTrap();
		FragTrap( string name );
		FragTrap( FragTrap const & src );
		
		~FragTrap();

		void			printStatus( void );
		void 			highFivesGuys( void );
		
};

#endif // FRAGTRAP_HPP