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
		String s7 = "abc ef gh";

        // TEST
		std::vector<String> s8 = s7.split(' ');

        // VERIFY
        assert(s8.size() == 3);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
		String s7 = "abc ef gh";

        // TEST
		std::vector<String> s8 = s7.split(' ');
		
        // VERIFY
        assert(s8.at(0) == "abc");
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
		String s7 = "abc ef gh";

        // TEST
		std::vector<String> s8 = s7.split(' ');

        // VERIFY
        assert(s8.at(1) == "ef");
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
		String s7 = "abc ef gh";

        // TEST
		std::vector<String> s8 = s7.split(' ');
		
        // VERIFY
        assert(s8.at(2) == "gh");
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
		String s7 = "-a--b-";
        
        // TEST
		std::vector<String> s8 = s7.split('-');

        // VERIFY
        assert(s8.size() == 5);
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
		String s7 = "-a--b-";        
		
        // TEST
		std::vector<String> s8 = s7.split('-');

        // VERIFY
        assert(s8.at(0) == "");
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
		String s7 = "-a--b-";
        
        // TEST
		std::vector<String> s8 = s7.split('-');

        // VERIFY
        assert(s8.at(1) == "a");
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
		String s7 = "-a--b-";
        
        // TEST
		std::vector<String> s8 = s7.split('-');

        // VERIFY
        assert(s8.at(2) == "");
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
		String s7 = "-a--b-";

        // TEST
		std::vector<String> s8 = s7.split('-');

        // VERIFY
        assert(s8.at(3) == "b");
    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE
		String s7 = "-a--b-";
        
        // TEST
		std::vector<String> s8 = s7.split('-');

        // VERIFY
        assert(s8.at(4) == "");
    }
	
    std::cout << "Done testing split()." << std::endl;
}

