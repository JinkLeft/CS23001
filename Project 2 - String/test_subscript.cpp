//  String class test program
//
//  Tests: testing the subscript operator Str[i]
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
        String s1("dog");


        // TEST
        

        // VERIFY
        assert(s1[0] == 'd');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");


        // TEST


        // VERIFY
        assert(s1[1] == 'o');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");


        // TEST


        // VERIFY
        assert(s1[2] == 'g');
    }
    std::cout << "Done testing subscript." << std::endl;
}

