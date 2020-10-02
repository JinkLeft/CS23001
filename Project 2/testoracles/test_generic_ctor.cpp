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
	char s1 = 's';

        // TEST
        String  str(s1);

        // VERIFY
        assert(str == 's');
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
    
    std::cout << "Done testing XXX." << std::endl;

}

