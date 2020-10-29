/*
 * David Russell
 * bigint.hpp
 * CS 23001
 * This is the header file for bigint.cpp
*/

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

	bool operator== (const bigint& numbers) const;
	// Compares two big int numbers and returns bool
	bigint operator+ (const bigint&) const;
	// Adds two bigints together and returns bigint
	int operator[] (const int i) const;
	// Return the i-th digit, where i is the 10^i pos
	bigint operator* (const bigint b) const;
	//multiply a bigint by a bigint

	void debugPrint(std::ostream&) const;
	// Prints elements of array starting from High end
	bigint timesDigit(int) const;
	//Multiply a bigint and a single digit integer between 0-9.
	bigint times10(int) const;
	//multiply a bigint by 10^n with n > 0
	friend std::ostream& operator<< (std::ostream& out,const bigint& b);
	//Writes bigint to stream
	friend std::istream& operator>> (std::istream& in, bigint& b);
	//Reads in any number of digits until a semicolon ';' is encountered.
};

#endif
