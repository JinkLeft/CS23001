//  String class test program
//
//  Tests: Default Ctor
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
        String s1;
        String s2;

        // TEST


        // VERIFY
        assert(s1 == s2);
    }

    std::cout << "Done testing default String Ctor." << std::endl;

}

