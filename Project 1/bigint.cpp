/**
 * David Russell
 * bigint
 * CS 23001
 * This program allows a user to input an int that is larger than a signed int.
*/

#include "bigint.hpp"

// CONSTRUCTORS
bigint::bigint () {
	for(int i = 0; i < CAPACITY; ++i) {
		bigIntArr[i] = 0;
	}
};

bigint::bigint (int userNum) {

	int i = 0;

	while(i < CAPACITY) {
		if ( userNum > 0) {
			bigIntArr[i] = userNum % 10;
			userNum /= 10;
		} else {
			bigIntArr[i] = 0;
		}
		++i;
	}
};

bigint::bigint (const char arr[]) {
	bool foundNull = false; 
	int countOfChars = 0;

	//Counts the Characters of the array, and sets the null and remaining indexes to 0
	for (int i = 0; i < CAPACITY; ++i) {
		if (arr[i] == '\0' || foundNull) {
			foundNull = true;
			bigIntArr[i] = 0;
		}
		if (arr[i] != '\0' && !foundNull) {
			++countOfChars;
		}
	}

	//Makes the char array keep the same order as ints.
	for (int i = 0, j = countOfChars -1; i < countOfChars; ++i, --j) {
		bigIntArr[i] = (int)(arr[j]) - 48;
		// Subtracts the int value of arr from 48 which is ASCII of 0;
	}

}

// METHODS
bool bigint::operator== (const bigint& rhs) const {
	bool isEqual = true;

	for (int i = 0; i < CAPACITY; ++i) {
		if (bigIntArr[i] != rhs.bigIntArr[i]) {
			isEqual = false;
		}
	}

	return isEqual;
}

//debugging of big int, outputs the int to the stream.
void bigint::debugPrint(std::ostream& out) const {
	for (int i = CAPACITY - 1; i >= 0; --i){
		out << bigIntArr[i];
		if (i > 0) {
			out  <<  "|";
		}
	}

	out << std::endl;
}


//Takes a stream and bigint and outputs that int to the stream and returns the stream.
std::ostream& operator << (std::ostream& out, bigint b) {
	bool detectedNumbers = false;
	const int maxLineSize = 80;
	int currentLineSize = 0;

	for (int i = CAPACITY - 1; i >= 0; --i) {
		if (b.bigIntArr[i] > 0 && !detectedNumbers){
			out << b.bigIntArr[i];
			++currentLineSize;
			detectedNumbers = true;
		} else if (b.bigIntArr[i] >= 0 &&  detectedNumbers) {
			out << b.bigIntArr[i];
			++currentLineSize;
		} else if (i == 0 && !detectedNumbers){
			out << 0;
		}

		//Resets line size counter
		if(currentLineSize == maxLineSize) {
			out << std::endl;
			currentLineSize = 0;
		}
	}

	return out;
}
