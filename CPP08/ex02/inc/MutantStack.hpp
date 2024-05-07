/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:21:44 by maroy             #+#    #+#             */
/*   Updated: 2024/05/06 20:51:41 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack: public std::stack<T>{

	public:

		MutantStack() : std::stack<T>() {};
		MutantStack(const MutantStack &src) : std::stack<T>(src) {};
		virtual ~MutantStack() {};

		MutantStack & operator=(const MutantStack &src){
			std::stack<T>::operator=(src);
			return *this;
		};

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(){
			return std::stack<T>::c.begin();
		};

		iterator end(){
			return std::stack<T>::c.end();
		};

	
};


#endif // MUTANTSTACK_HPP
