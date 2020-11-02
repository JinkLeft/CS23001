//  Stack class test program
//
//  Tests: XXX
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int> test, blank;

        // VERIFY
		assert(test == blank);
		assert(test.empty());
		assert(blank.empty());


    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char> test, blank;

        // VERIFY

		assert(test.empty());
		assert(blank.empty());


    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing default ctor." << std::endl;

}

