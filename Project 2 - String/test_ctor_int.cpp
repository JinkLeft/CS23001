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
        String s1(10);

        // TEST


        // VERIFY
        assert(s1.capacity() == 10);
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1(1);

        // TEST


        // VERIFY
        assert(s1.capacity() == 1);
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1(0);

        // TEST


        // VERIFY
        assert(s1.capacity() == 0);
    }

    std::cout << "Done testing ctor(int)." << std::endl;

}