//  String class test program
//
//  Tests: XXX
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
	String s1('c');
	String s2('c');

        // TEST
       

        // VERIFY
        assert(s1 == s2);
    }
/*
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(X);

        // VERIFY
        assert(str == YYY);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(X);

        // VERIFY
        assert(str == YYY);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(X);

        // VERIFY
        assert(str == YYY);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(X);

        // VERIFY
        assert(str == YYY);
    }
*/
    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing Generic String Ctor." << std::endl;

}

