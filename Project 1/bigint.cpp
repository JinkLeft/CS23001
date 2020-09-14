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
		bigIntArr[i] = 0;
		if (arr[i] == '\0' || foundNull) { foundNull = true; }
		if (arr[i] != '\0' && !foundNull) { ++countOfChars; }
	}

	//Makes the char array keep the same order as ints.
	for (int i = 0, j = countOfChars -1; i < countOfChars; ++i, --j) {
		if(arr[j] != ' ' && arr[j] != ';' && arr[j] != '\n') {
			bigIntArr[i] = (int)(arr[j]) - 48;
			// Subtracts the int value of arr from 48 which is ASCII of 0;
		}
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

bigint bigint::operator+ (const bigint& rhs) const {
	int oneCarry = 0;
	int tempValue = 0;
	bigint newBigInt;

	for (int i = 0; i < CAPACITY; ++i) {
		if (tempValue >= 0 && oneCarry == 0) {
			tempValue = bigIntArr[i] + rhs.bigIntArr[i];
			newBigInt.bigIntArr[i] = tempValue % 10;

			if( tempValue >= 10) { oneCarry = 1;}
		} else if (tempValue == 0 && oneCarry == 1) {
			tempValue = bigIntArr[i] + rhs.bigIntArr[i] + oneCarry;

			if (tempValue >= 10) {
				newBigInt.bigIntArr[i] = tempValue % 10;
				oneCarry = 1;
			} else {
				newBigInt.bigIntArr[i] = tempValue;
				oneCarry = 0;
			}
 		}

		tempValue = 0;	// Reset temp value
	}

	return newBigInt;
}

int bigint::operator[] (const int i) const {
	return bigIntArr[i];
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
std::ostream& operator << (std::ostream& out,const bigint& b) {
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

std::istream& operator>> (std::istream& in, bigint& b) {
	char str[CAPACITY];
	bool foundNull = false;
	int countOfChars = 0;

	in.getline(str, CAPACITY, ';');

	//Counts the Characters of the array, and sets the null and remaining indexes to 0
	for (int i = 0; i < CAPACITY; ++i) {
		if (str[i] == '\0' || foundNull) {
			foundNull = true;
			b.bigIntArr[i] = 0;
		}

		if (str[i] != '\0' && !foundNull) { ++countOfChars; }
	}

	//Makes the char array keep the same order as ints.
	for (int i = 0, j = countOfChars -1; i < countOfChars; ++i, --j) {
		b.bigIntArr[i] = (int)(str[j]) - 48;
		// Subtracts the int value of arr from 48 which is ASCII of 0;
	}

	return in;
}
