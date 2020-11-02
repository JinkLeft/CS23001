//  Stack class test program
//
//  Tests: XXX
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int> test, result;

		test.push(1);
		test.push(2);
		
		result = test;

		

        // VERIFY
		assert(test == result);

		assert(test.getLength() == 2);
		assert(result.getLength() == 2);

    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int> test, result;

		test.push(1);
		test.push(2);
		
		result = test;

		

        // VERIFY
		assert(test == result);

		assert(test.getLength() == 2);
		assert(result.getLength() == 2);
		
		test.pop();
		
		assert(test.getLength() == 1);
		assert(result.getLength() == 2);
		
		result.pop();
		
		assert(test.getLength() == 1);
		assert(result.getLength() == 1);
		
		test.pop();
		result.pop();
		
		assert(test.empty());
		assert(result.empty());

    }
	
	    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char> test, result;

		test.push('1');
		test.push('2');
		
		result = test;

		

        // VERIFY
		assert(test == result);

		assert(test.getLength() == 2);
		assert(result.getLength() == 2);

    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char> test, result;

		test.push('1');
		test.push('2');
		
		result = test;

		

        // VERIFY
		assert(test == result);

		assert(test.getLength() == 2);
		assert(result.getLength() == 2);
		
		test.pop();
		
		assert(test.getLength() == 1);
		assert(result.getLength() == 2);
		
		result.pop();
		
		assert(test.getLength() == 1);
		assert(result.getLength() == 1);
		
		test.pop();
		result.pop();
		
		assert(test.empty());
		assert(result.empty());

    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing Push() Pop()." << std::endl;

}

