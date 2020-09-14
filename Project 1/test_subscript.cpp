// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {

    {
        // Setup
        bigint bi(4);

        // Test
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  //Fixed.
        assert(digit == 4);
    }
    {
        // Setup
        bigint bi(3210);

        // Test
        int digit = bi[2];

        // Verify
        assert(bi    == 3210);  //Added test Cases.
        assert(digit == 2);
    }

    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
}

