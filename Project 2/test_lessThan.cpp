//  String class test program
//
//  Tests: < operator
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
        String s1("abc");
        String s2("abcd");

        // TEST


        // VERIFY
        assert(s1 < s2);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        // Test 
        String s1("abcde");
        char s2[] = "abcd";

        // Verify
        assert(s2 < s1);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        // Test 
        String s1("abcde");
        char s2 = 'a';

        // Verify
        assert(s2 < s1);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        // Test String and <= operator
        // Test 
        String s1("abcde");
        String s2 = "abcde";

        // Verify
        assert(s1 <= s2);
    }
    std::cout << "Done testing < operator." << std::endl;

}