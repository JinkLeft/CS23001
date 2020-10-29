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
        String s2("");

        // TEST
		s1.swap(s2);

        // VERIFY
        assert(s1 == "");
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("");
        String s2("abc");

        // TEST
		s1.swap(s2);
		
        // VERIFY
        assert(s1 == "abc");
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("");
        String s2("");

        // TEST
		s1.swap(s2);
		
        // VERIFY
        assert(s1 == "");
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("abc");
        String s2("abc");

        // TEST
		s1.swap(s2);
		
        // VERIFY
        assert(s1 == "abc");
    }
		{
        //------------------------------------------------------
        // SETUP FIXTURE
        String s1("def");
        String s2("abc");

        // TEST
		s1.swap(s2);
		
        // VERIFY
        assert(s1 == "abc");
    }
    std::cout << "Done testing swap assign." << std::endl;

}