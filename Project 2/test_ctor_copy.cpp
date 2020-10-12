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
        String s2(s1);

        // TEST


        // VERIFY
        assert(s1 == s2);
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1('a');
        String s2(s1);

        // TEST

        // VERIFY
        assert(s1 == s2);
    }
    {
        //------------------------------------------------------
        // Test: Construct with 1
        // Setup fixture

        // Test 
        String s1("");
		String s2(s1);

        // Verify
        assert(s1 == s2);
    }

    {
        //------------------------------------------------------
        // Test: Construct with three char value
        // Setup fixture

        // Test 
        String s1("abc");
		String s2(s1);

        // Verify
        assert(s1 == s2);
    }


    {
        //------------------------------------------------------
        // Test: Construct with large character String
        // Setup fixture

        // Test
        String s1("6234567890");

        // Verify
        assert(s1 == "6234567890");

        s1 = String("62345");   //Check re-assignment.
		String s2(s1);

        // Verify
        assert(s1 == s2);

    }

    std::cout << "Done testing copy String Ctor." << std::endl;

}