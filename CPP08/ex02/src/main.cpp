/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:35:08 by maroy             #+#    #+#             */
/*   Updated: 2024/07/30 13:28:54 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <algorithm>
#include <typeinfo>

#define PRINT(x) std::cout << std::boolalpha << x << std::endl;
#define PUT_DELIM std::cout << std::string(40, '-') << std::endl;
#define PUT_HEADER(x)  std::cout << std::string(40, '*') << std::endl << "TEST : " << x << std::endl << std::string(40, '*') << std::endl;


int main() {

    // Test for Empty Stack Operations
    {
        PUT_HEADER("Empty Stack Operations");
        MutantStack<int> mstack;
        PRINT("Is stack empty? " << mstack.empty());
        PUT_DELIM
        try {
            mstack.pop();
        } catch (const std::exception &e) {
            PRINT("Exception on pop from empty stack: " << e.what());
        }
        PUT_DELIM
    }
    PRINT('\n') 
    // Test for Stack with Single Element
    {
        PUT_HEADER("Stack with Single Element");
        MutantStack<int> mstack;
        mstack.push(42);
        PRINT("top: " << mstack.top());
        PUT_DELIM
        PRINT("size: " << mstack.size());
        PUT_DELIM
        mstack.pop();
        PRINT("Is stack empty? " << mstack.empty());
        PUT_DELIM
    }
    PRINT('\n') 
    // Test for Stack with Multiple Elements
    {
        PUT_HEADER("Stack with Multiple Elements");
        MutantStack<int> mstack;
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
        PRINT("size: " << mstack.size());
        PUT_DELIM

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        PRINT("Sorting Container Elements...");
        std::sort(mstack.begin(), mstack.end());
        PUT_DELIM;
        PRINT("Pop All Elements")
        while (it != ite) {
            mstack.pop();
            ++it;
        }
        PUT_DELIM
        PRINT("Is stack empty? " << (mstack.empty() ? "Yes" : "No"));
    }
    PRINT('\n') 
    {
        PUT_HEADER("Iterating Over Stack Elements")
        MutantStack<char> mstack;
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
            // PRINT("Is stack empty? " << (mstack.empty() ? "Yes" : "No"))
            ++it;
        }
        PUT_DELIM
        PRINT("Is stack empty? " << (mstack.empty() ? "Yes" : "No"))
    }
    PRINT('\n') 
    // Test for Iterating Over Stack Elements
    {
        PUT_HEADER("Iterating Over Stack Elements");
        MutantStack<char> mstack;
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
        PRINT("size: " << mstack.size());
        PUT_DELIM

        PRINT("Iterating over elements:");
        for (MutantStack<char>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            PRINT(*it);
        }
        PUT_DELIM
    }
    PRINT('\n');
    // Test for Copy Constructor and Assignment Operator
    {
        PUT_HEADER("Copy Constructor and Assignment Operator");
        MutantStack<std::string> mstack;
        mstack.push("apple");
        mstack.push("banana");
        mstack.push("cherry");

        PRINT("Original stack top: " << mstack.top());
        PUT_DELIM

        MutantStack<std::string> mstack_copy(mstack);
        PRINT("Copy stack top: " << mstack_copy.top());
        PUT_DELIM

        MutantStack<std::string> mstack_assigned;
        mstack_assigned = mstack;
        PRINT("Assigned stack top: " << mstack_assigned.top());
        PUT_DELIM
    }
    
    PRINT('\n');
    {
        PUT_HEADER("Complex Type (string)")
        MutantStack<std::string> mstack;
        mstack.push("apple");
        mstack.push("banana");
        mstack.push("cherry");
        mstack.push("date");
        mstack.push("elderberry");
        mstack.push("fig");
        mstack.push("grape");
        mstack.push("honeydew");
        mstack.push("kiwi");
        mstack.push("lemon");

        PRINT("top: " << mstack.top());
        PUT_DELIM
        PRINT("size: " << mstack.size())
        PUT_DELIM

        MutantStack<std::string>::iterator it = mstack.begin();
        MutantStack<std::string>::iterator ite = mstack.end();

        PRINT("Sorting Container Elements...");
        std::sort(mstack.begin(), mstack.end());
        PUT_DELIM;

        PRINT("Pop All Elements")
        while (it != ite) {
            mstack.pop();
            // PRINT("Is stack empty? " << (mstack.empty() ? "Yes" : "No"))
            ++it;
        }
        PUT_DELIM
        PRINT("Is stack empty? " << (mstack.empty() ? "Yes" : "No"))
    }
    PRINT('\n')

    return 0;
}
