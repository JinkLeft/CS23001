//  String class test program
//
//  Tests: testing the find String method
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
        int location = s1.findstr(0, "dog");


        // VERIFY
        assert(location == 0);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");


        // TEST
        int location = s1.findstr(0, "og");

        // VERIFY
        assert(location == 1);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");


        // TEST
        int location = s1.findstr(0, 'g');

        // VERIFY
        assert(location == 2);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");


        // TEST
        int location = s1.findstr(0, 'a');

        // VERIFY
        assert(location == -1);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog is a boy");



        // TEST
        int location = s1.findstr(0, "is");

        // VERIFY
        assert(location == 4);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog is a boy");



        // TEST
        int location = s1.findstr(6, "is");

        // VERIFY
        assert(location == -1);

    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog is a boy");


        // TEST
        int location = s1.findstr(1, "dog");


        // VERIFY
        assert(location == -1);

    }
    std::cout << "Done testing findstr." << std::endl;
}

