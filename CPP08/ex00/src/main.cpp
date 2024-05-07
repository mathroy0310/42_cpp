/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:07:47 by maroy             #+#    #+#             */
/*   Updated: 2024/05/06 17:16:58 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main(void)
{
	
	std::cout << "Testing with a vector of int" << std::endl;
	
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	try {
		easyfind(vec, 6);
	}
	catch (std::exception &e) {
		std::cout << "Value not found" << std::endl;
	}

	std::cout << std::endl << "Testing with a vector of string" << std::endl;
	
	std::


	return 0;
}
