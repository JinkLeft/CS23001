/**
 * David Russell
 * String
 * CS 23001
 * Creating our own implimentation of the string ADT
*/
#include "String.hpp"

//CONSTRUCTORS
String::String()
{
	str[0] = '\0';
}

String::String(char c)
{
	str[0] = c;
	str[1] = '\0';
}

String::String(const char[] cArr)
{
	int i = 0;

	for(i = 0; i < STRING_SIZE; ++i)
	{
		str[i] = cArr[i];

		if(cArr[i] == '\0') {
			break;
		}
	}

	str[i] = '\0';
}

//METHODS
int String::capacity() const
{
	return STRING_SIZE -1;
}

int String::length() const
{
	int i;

	for(i = 0; i < STRING_SIZE; ++i)
	{
		if(str[i] == '\0') {
			break;
		}
	}

	return i;
}

//OPERATORS
char& String::operator[] (int index)
{
	return str[index];
}

char String::operator[] (int index) const
{
	return str[index];
}

std::istream& operator>>(std::istream& in, String& right)
{
	char ch, charArr[STRING_SIZE];
	//charArr[0]= '\0';

	in >> ch;
	for(int i = 0; i < STRING_SIZE && ch != '\0'; ++i)
	{
		charArr[i] = ch;
		in >> ch;
	}

	right = String(charArr);

	return in;
}

std::ostream& operator<<(std::ostream& out, const String& right)
{
	int size = STRING_SIZE;
	bool nullFound = false;

	for(int i = 0; i < STRING_SIZE; ++i)
	{

		if(str[i] == '\0')
			nullFound = true;

		if(!nullFound)
			out << right.str[i];
	}

	return out;
}

String String::operator+ (const String& rhs) const
{
	String temp;
	int rhsLenght = rhs.lenght();
	int lhsLenght = 0;

	for(int i = 0; i < STRING_SIZE; ++i)
	{
		if(str[i] == '\0')
			lhsLength = i;
			break;
	}

	for(int i = 0; i < lhsLength)
	{
		temp.str[i] = str[i];
	}

	for(int i = lhsLength, int j = 0; i < STRING_SIZE - 2; ++i, ++j)
	{
		temp.str[i] = rhs.str[j];
	}

	int totalLength = (rhsLength + lhsLength);

	if( totalLength < (STRING_SIZE - 1))
	{
		temp.str[totalLength] = '\0';
	}
	else if( totalLenght > (STRING_SIZE -1 || totalLenght == (STRING_SIZE -1))
	{
		temp.str[STRING_SIZE -1] = '\0';
	}

	return temp;
}

String String::operator+ (const char[] cArr, const String& rhs);
{
	return String(cArr) + rhs;
}

String String::operator+ (char c, const String& rhs)
{
	return String(c) + rhs;
}

bool String::operator== (const String& right)  const
{
	bool isEqual = true;

	for(int i = 0; i < STRING_SIZE; ++i)
	{
		if(str[i] != right.str[i])
		{
			isEqual = false;
		}
	}

	return isEqual;
}

bool String::operator== (const char[], const String&);
bool String::operator== (char, const String&);
bool String::operator< (const char[], const String&);
bool String::operator< (char, const String&);
bool String::operator<= (const String&, const String&);
bool String::operator!= (const String&, const String&);
bool String::operator>= (const String&, const String&);
bool String::operator> (const String&, const String&);
bool String::operator< (const String&) const;
