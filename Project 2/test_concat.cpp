//  String class test program
//
//  Tests: Concat testing += and +
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
        String s2 = s1 + "animal";

        // VERIFY
        assert(s2 == "doganimal");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");


        // TEST
        String s2 = s1 + 'a';

        // VERIFY
        assert(s2 == "doga");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");


        // TEST
        s1 += "animal";
    	
        // VERIFY
        assert(s1 == "doganimal");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("dog");
        String s2("");

        // TEST
        s1 += s2;

        // VERIFY
        assert(s1 == "dog");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("");
        String s2("dog");

        // TEST
        s1 += s2;

        // VERIFY
        assert(s1 == "dog");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("");
        String s2("");

        // TEST
        s1 += s2;

        // VERIFY
        assert(s1 == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("abc");
        String s2("");

        // TEST
        String s3 = s1 + s2;

        // VERIFY
        assert(s3 == "abc");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("");
        String s2("");

        // TEST
        String s3 = s1 + s2;

        // VERIFY
        assert(s3 == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("");
        String s2("abc");

        // TEST
        String s3 = s1 + s2;

        // VERIFY
        assert(s3 == "abc");
    }
    std::cout << "Done testing concat." << std::endl;
}

