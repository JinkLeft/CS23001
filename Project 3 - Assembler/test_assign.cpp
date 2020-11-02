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
        stack<String> test, result;

		test.push("01");
		test.push("02");
		
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

    }
	{
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int> test, result;

		test.push(1);
		test.push(2);
		test.push(3);
		test.push(4);
		
		result = test;

		

        // VERIFY
		assert(test == result);

		assert(test.getLength() == 4);
		assert(result.getLength() == 4);
		
		test.pop();
		
		assert(test.getLength() == 3);
		assert(result.getLength() == 4);
		
		test = result;
		
		result.pop();
		
		assert(test.getLength() == 4);
		assert(result.getLength() == 3);
		
		test.pop();
		result.pop();
		
		assert(!test.empty());
		assert(!result.empty());

    }
	
	{
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char> test, result, blank;

		test.push('1');
		test.push('2');
		
		result = test;

		

        // VERIFY
		assert(test == result);

		assert(test.getLength() == 2);
		assert(result.getLength() == 2);
		
		test = blank;
		
		assert(test == blank);

		assert(test.empty());
		assert(blank.empty());
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
    
    std::cout << "Done testing assign =." << std::endl;

}

