//==============================================================================
// Basics for openning a file for milestone 2 of Project 1.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-2.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-2.txt, exiting." << std::endl;
        exit(1);
    }

	char firstInt[CAPACITY];
	char secondInt[CAPACITY];

	while(!in.eof()) {
		if(in.getline(firstInt, CAPACITY, ';') && in.getline(secondInt, CAPACITY, ';')){

			bigint b1(firstInt);
			bigint b2(secondInt);

			bigint b3 = (b1 * b2);

			std::cout << "\n  " << b1 << std::endl;
			std::cout << "* " << b2 << std::endl;
			std::cout << "= " << b3 << std::endl;
		}
	}

	if(in.eof()) {
		std::cout << "\nEOF REACHED " << std::endl;
	}

    in.close();

    return 0;
}
