// bigint Test Program
//
// Tests:  int constructor, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      // TESTING CHAR CTOR with CHAR CTOR
      bigint left("123450");
      bigint right("123451");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 123450);
      assert(right  == 123451);
      assert(result == 246901);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      // TESTING CHAR CTOR with CHAR CTOR
      bigint left("123450");
      bigint right(123451);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 123450);
      assert(right  == 123451);
      assert(result == 246901);
    }

    //FIXED ASSERTION

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(123);
      bigint right(112);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 123);
      assert(right  == 112);
      assert(result == 235);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(123);
      bigint right(1124);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 123);
      assert(right  == 1124);
      assert(result == 1247);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(123);
      bigint right(12);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 123);
      assert(right  == 12);
      assert(result == 135);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(123);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 123);
      assert(right  == 0);
      assert(result == 123);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(0);
      bigint right(112);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 0);
      assert(right  == 112);
      assert(result == 112);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(0);
      bigint right(1112);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 0);
      assert(right  == 1112);
      assert(result == 1112);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(0);
      bigint right(12);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 0);
      assert(right  == 12);
      assert(result == 12);
    }
    //Add test cases as needed.


    std::cout << "Done with testing addition." << std::endl;
}

