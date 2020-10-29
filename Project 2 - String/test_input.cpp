//  String class test program
//
//  Tests: testing the input operator std::cin >> Str;
//

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>

//===========================================================================
int main()
{
    {
		std::ifstream in("data.txt");			// Define stream for input
		if (!in) {								// Make sure it opened correctly.
			std::cerr << "Could not open data.txt, exiting." << std::endl;
			exit(1);
		}
		int i = 0;
		while (!in.eof()) {
			String str;
			if (in >> str) {
				std::cout << str << std::endl;


				if (i == 0)
					assert(str == "dog");
				if (i == 1)
					assert(str == "cat");
				if (i == 2)
					assert(str == "animal");
				if (i == 3)
					assert(str == "word");
				if (i == 4)
					assert(str == "1234");
				if (i == 5)
					assert(str == "second");
				if (i == 6)
					assert(str == "random");

				++i;
			}
		}
		in.close();
    }
    std::cout << "Done testing input operator." << std::endl;
}

