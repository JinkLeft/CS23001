//  String class test program
//
//  Tests: testing the sub String method
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
        String s1("dog is a boy");


        // TEST
        String s2 = s1.substr(0, 2);


        // VERIFY
        assert(s2 == "dog");

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog is a boy");


        // TEST
        String s2 = s1.substr(4, 5);

        // VERIFY
        assert(s2 == "is");

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog is a boy");


        // TEST
        String s2 = s1.substr(9, 11);


        // VERIFY
        assert(s2 == "boy");

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog is a boy");


        // TEST
        String s2 = s1.substr(12, 13);


        // VERIFY
        assert(s2 == "");

    }
    std::cout << "Done testing substring." << std::endl;
}

