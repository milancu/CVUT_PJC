//
// Created by Milan on 19.12.2021.
//

#ifndef TEST_TEST_HPP
#define TEST_TEST_HPP


#include <iostream>

class my_class {
public:
    my_class() {
        std::cout << "Hello\n";
    }
    ~my_class() {
        std::cout << "Bye Bye\n";
    }
    void stuff() {
        std::cout << "Stuff\n";
    }
};


#endif //TEST_TEST_HPP
