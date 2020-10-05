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
        int len = s1.length();
        int cap = s1.capacity();

        // VERIFY
        assert(len == 3);
        assert(cap == 255);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog1");


        // TEST
        int len = s1.length();
        int cap = s1.capacity();

        // VERIFY
        assert(len == 4);
        assert(cap == 255);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog12");


        // TEST
        int len = s1.length();
        int cap = s1.capacity();

        // VERIFY
        assert(len == 5);
        assert(cap == 255);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("");


        // TEST
        int len = s1.length();
        int cap = s1.capacity();

        // VERIFY
        assert(len == 0);
        assert(cap == 255);
    }
    std::cout << "Done testing length and capacity." << std::endl;
}

