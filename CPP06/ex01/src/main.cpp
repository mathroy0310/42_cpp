/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:25:54 by maroy             #+#    #+#             */
/*   Updated: 2024/03/30 16:32:29 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include <string>

struct Data {
    std::string truc;
};

uintptr_t serialize(Data *ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}
Data *deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}

int main(void) {
    Data zig;

    zig.truc = "cest vrai";

    uintptr_t serialized = serialize(&zig);

    std::cout << serialized << std::endl;

    Data *ptr = deserialize(serialized);

    std::cout << ptr->truc << std::endl;
    return (0);
}