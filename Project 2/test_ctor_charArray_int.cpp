//  String class test program
//
//  Tests: Char array Ctor
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1(10, "abc");

        // TEST


        // VERIFY
        assert(s1.capacity() == 10);
		assert(s1 == "abc");
    }
	

    std::cout << "Done testing char int ctor." << std::endl;

}