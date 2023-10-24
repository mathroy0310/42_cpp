/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Brain.hpp                                        ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/24 11:39:07 by maroy                                    */
/*   Updated: 2023/10/24 11:47:58 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "common.hpp"

class Brain
{
  public:
	Brain();
	Brain(Brain const &src);
	~Brain();

	Brain &operator=(Brain const &src);
	// Setters - Getters
	string	*getIdeas( void );
	void	setIdeas(int i, string *ideas);
  protected:
	string _ideas[100];
};

#endif // BRAIN_HPP