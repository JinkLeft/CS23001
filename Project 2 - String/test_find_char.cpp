//  String class test program
//
//  Tests: testing the find Char method
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
        int location = s1.findch(0, 'd');

        // VERIFY
        assert(location == 0);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");
        


        // TEST
        int location = s1.findch(0, 'o');

        // VERIFY
        assert(location == 1);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");
        


        // TEST
        int location = s1.findch(0, 'g');

        // VERIFY
        assert(location == 2);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");
        


        // TEST
        int location = s1.findch(1, 'd');

        // VERIFY
        assert(location == -1);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");



        // TEST
        int location = s1.findch(1, 'o');

        // VERIFY
        assert(location == 1);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");



        // TEST
        int location = s1.findch(1, 'g');

        // VERIFY
        assert(location == 2);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");
        


        // TEST
        int location = s1.findch(0, 'a');

        // VERIFY
        assert(location == -1);

    }
    std::cout << "Done testing findch." << std::endl;
}

