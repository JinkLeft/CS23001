//Name: David Russell
//
//Date: 09/10/2020
//


#ifndef __BIGINT_HPP__
#define __BIGINT_HPP__

#include <iostream>

const int CAPACITY = 400;

class bigint {
private:
	int bigIntArr[CAPACITY];
public:
	bigint(); 			// Default constructor initialize to 0
	bigint(int userNum);		// Initializes the array to an int value
	bigint(const char arr[]);	// Initializes the array to a char value

	bool operator== (const bigint& numbers) const;	// Compares two big int numbers and returns bool
	bigint operator+ (const bigint&) const;		// Adds two bigints together and returns bigint

	void debugPrint(std::ostream&) const;		// Prints elements of array starting from High end
	friend std::ostream& operator << (std::ostream& out, bigint b);	 //Writes bigint to stream
};

#endif
