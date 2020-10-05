//  String class test program
//
//  Tests: char Ctor
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
        String s1('a');
        String s2('a');

        // TEST


        // VERIFY
        assert(s1 == s2);
    }

    std::cout << "Done testing default char Ctor." << std::endl;

}

