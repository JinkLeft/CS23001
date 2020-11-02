//  Stack class test program
//
//  Tests: XXX
//

#include "stack.hpp"
#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int> test, blank;

		test.push(1);
		test.push(2);
		
		blank = test;

		stack<int> result(blank);

        // VERIFY
		assert(test == result);

		assert(test.getLength() == 2);
		assert(result.getLength() == 2);

    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> test, blank;

		test.push("01");
		test.push("02");
		
		blank = test;

		stack<String> result(blank);

        // VERIFY
		assert(test == result);

		assert(test.getLength() == 2);
		assert(result.getLength() == 2);

    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char> test, blank;

		test.push('1');
		test.push('2');
		
		blank = test;

		

        stack<char> result(blank);

        // VERIFY
		assert(test == result);

		assert(test.getLength() == 2);
		assert(result.getLength() == 2);
		
		result.pop();
		
		assert(test.getLength() == 2);
		assert(blank.getLength() == 2);
		assert(result.getLength() == 1);
		
		result = blank;
		
		test.push('3');

		assert(test.getLength() == 3);
		assert(blank.getLength() == 2);
		assert(result.getLength() == 2);
		
		blank = test;
		result = blank;
		
		assert(test.getLength() == 3);
		assert(blank.getLength() == 3);
		assert(result.getLength() == 3);

    }	

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing copy ctor." << std::endl;

}

