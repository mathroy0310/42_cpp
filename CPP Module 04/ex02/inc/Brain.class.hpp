/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:39:07 by maroy             #+#    #+#             */
/*   Updated: 2023/10/24 22:00:38 by maroy            ###   ########.fr       */
/*                                                                            */
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
	string *getIdeas(void);
	void setIdeas(int i, string *ideas);

private:
	string *_ideas;
};

#endif // BRAIN_HPP