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
        String s1("abc");
        String s2("abc");

        // TEST


        // VERIFY
        assert(s1 == s2);
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1('a');
        String s2('a');

        // TEST

        // VERIFY
        assert(s1 == s2);
    }
    {
        //------------------------------------------------------
        // Test: Construct with 0
        // Setup fixture

        // Test 
        String s1('a');

        // Verify
        assert(s1 == 'a');
    }

    {
        //------------------------------------------------------
        // Test: Construct with 1
        // Setup fixture

        // Test 
        String s1("ab");

        // Verify
        assert(s1 == "ab");
    }

    {
        //------------------------------------------------------
        // Test: Construct with three char value
        // Setup fixture

        // Test 
        String s1("abc");

        // Verify
        assert(s1 == "abc");
    }


    {
        //------------------------------------------------------
        // Test: Construct with large character String
        // Setup fixture

        // Test
        String s1("6234567890");

        // Verify
        assert(s1 == "6234567890");
        std::cout << "6234567890 == ";
        std::cout << s1;
        std::cout << std::endl;

        s1 = String("62345");   //Check re-assignment.
        assert(s1 == "62345");
        std::cout << "62345 == ";
        std::cout << s1;
        std::cout << std::endl;


    }

    std::cout << "Done testing char[] String Ctor." << std::endl;

}