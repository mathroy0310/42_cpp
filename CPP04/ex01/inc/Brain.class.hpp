/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:39:07 by maroy             #+#    #+#             */
/*   Updated: 2023/11/13 15:51:29 by maroy            ###   ########.fr       */
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
    Brain(Brain &ref);
    ~Brain();

    Brain &operator=(Brain const &rhs);
    // Getters - Setters
    string getIdea(unsigned int i) const;
    void   setIdea(unsigned int i, string ideas);

  private:
    string *_ideas;
};

#endif // BRAIN_HPP