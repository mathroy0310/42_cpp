/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:35:08 by maroy             #+#    #+#             */
/*   Updated: 2024/05/10 19:00:47 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <algorithm>
#include <typeinfo>

#define PRINT(x) std::cout << std::boolalpha << x << std::endl;
#define PUT_DELIM std::cout << std::string(40, '-') << std::endl;
#define PUT_HEADER(x)                                       \
    std::cout << std::string(40, '*') << std::endl          \
              << "TEST : " << typeid(x).name() << std::endl \
              << std::string(40, '*') << std::endl;

int main() {

    {
        MutantStack<int> mstack;
        PUT_HEADER(mstack);
        mstack.push(1);
        mstack.push(52);
        mstack.push(3);
        mstack.push(64);
        mstack.push(5);
        mstack.push(16);
        mstack.push(7);
        mstack.push(80);
        mstack.push(39);
        mstack.push(100);

        PRINT("top: " << mstack.top());
        PUT_DELIM
        PRINT("size: " << mstack.size())
        PUT_DELIM

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        PRINT("Sorting Container Elements...");
        std::sort(mstack.begin(), mstack.end());
        PUT_DELIM;
        PRINT("Pop All Elements")
        while (it != ite) {
            PRINT(*it << ": got popped!");
            mstack.pop();
            // PRINT("Is stack empty? " << (mstack.empty() ? "Yes" : "No"))
            ++it;
        }
        PUT_DELIM
        PRINT("Is stack empty? " << (mstack.empty() ? "Yes" : "No"))
    }
    PRINT('\n') {
        MutantStack<char> mstack;
        PUT_HEADER(mstack)
        mstack.push('a');
        mstack.push('f');
        mstack.push('d');
        mstack.push('i');
        mstack.push('m');
        mstack.push('c');
        mstack.push('e');
        mstack.push('g');
        mstack.push('b');
        mstack.push('k');
        mstack.push('j');
        mstack.push('n');
        mstack.push('h');
        mstack.push('l');

        PRINT("top: " << mstack.top());
        PUT_DELIM
        PRINT("size: " << mstack.size())
        PUT_DELIM

        MutantStack<char>::iterator it = mstack.begin();
        MutantStack<char>::iterator ite = mstack.end();

        PRINT("Sorting Container Elements...");
        std::sort(mstack.begin(), mstack.end());
        PUT_DELIM;

        PRINT("Pop All Elements")
        while (it != ite) {
            mstack.pop();
            PRINT(*it << ": got popped!");
            // PRINT("Is stack empty? " << (mstack.empty() ? "Yes" : "No"))
            ++it;
        }
        PUT_DELIM
        PRINT("Is stack empty? " << (mstack.empty() ? "Yes" : "No"))
    }
    PRINT('\n')

    return 0;
}
