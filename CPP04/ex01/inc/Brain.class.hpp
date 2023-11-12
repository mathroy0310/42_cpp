/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Brain.class.hpp                                   ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/24 11:39:07 by maroy                                    */
/*   Updated: 2023/11/11 17:01:53 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "common.hpp"

class Brain
{
public:
	Brain();
	Brain(Brain &rhs);
	~Brain();

	Brain &operator=(Brain const &ref);
	// Setters - Getters
	string getIdea(int i) const;
	void setIdea(int i, string ideas);

private:
	string *_ideas;
};

#endif // BRAIN_HPP