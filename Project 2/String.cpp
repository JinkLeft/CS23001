/**
 * David Russell
 * String
 * CS 23001
 * Creating our own implementation of the string ADT
*/
#include "string.hpp"

String::String(int size) {                                               //String(10) - capacity 10, empty string
	stringSize = size;
	str = new char[stringSize];
	str[0] = '\0';
}

void String::resetCapacity(int newSize)
{
	const auto currentSize = stringSize;
	
	if (currentSize >= newSize)
		return;

	auto* str2 = new char[newSize];

	for (auto i = 0; i < stringSize; i++)
	{
		str2[i] = str[i];
	}

	delete[] str;
	
	str = str2;
}

String::String(const int size, const char c[])
{

	stringSize = size + 1;
	str = new char[stringSize];

	for (auto j = 0; j < stringSize; ++j)
	{
		if (j != stringSize - 1)
		{
			str[j] = c[j];
		}
		else
		{
			str[j] = '\0';
		}
	}
}


//default ctor
String::String()
{
	stringSize = 1;
	str = new char[stringSize];
	str[0] = '\0';
}

String::String(char c)
{
	stringSize = 2;
	str = new char[stringSize];

	str[0] = c;
	str[1] = '\0';
}

String::String(const char c[])
{
	int i = 0;
	while (c[i] != '\0')
	{
		++i;	
	}
	
	stringSize = i + 1;
	str = new char[stringSize];

	for (auto j = 0; j < stringSize; ++j)
	{
		str[j] = c[j];
	}
}

String::String(const String& rhs)
{
	stringSize = rhs.stringSize;
	str = new char[stringSize];

	for(auto i = 0; i < stringSize; ++i)
	{
		str[i] = rhs.str[i];
	}
}

String::~String()
{
	delete[] str;
}

void String::swap(String& rhs)
{
	//Swap the strings
	char* temp = str;
	str = rhs.str;
	rhs.str = temp;

	//Swap the size
	const auto size = stringSize;
	stringSize = rhs.stringSize;
	rhs.stringSize = size;
}

String& String::operator=(String rhs)
{
	if (str != nullptr)
		delete[] str;

	str = nullptr;

	stringSize = rhs.stringSize;

	str = new char[stringSize];

	for (auto i = 0; i < stringSize; ++i)
	{
		str[i] = rhs.str[i];
	}

	return *this;
}

char& String::operator[](int index)
{
	return str[index];
}

char String::operator[](int index) const
{
	return str[index];
}

int String::capacity() const
{
	return stringSize - 1;
}

int String::length() const
{
	auto length = 0;
	for(auto i = 0; i < stringSize; ++i)
	{
		if(str[i] == '\0')
		{
			length = i;
			return length;
		}
	}

	return length;
}

 
String String::operator+(const String& rhs) const
{

	const auto lhsSizeOffset = stringSize - 1;
	const auto rhsSize = rhs.stringSize - 1;
	const auto totalSize = lhsSizeOffset + rhsSize;

	String temp(totalSize + 1);
	
	for(auto i = 0; i < totalSize; ++i)
	{
		if (i < lhsSizeOffset)
		{
			temp.str[i] = str[i];
		}
		if(i >= lhsSizeOffset && i < totalSize)
		{
			temp.str[i] = rhs.str[i - lhsSizeOffset];
		}
		
	}
	
	temp.str[totalSize] = '\0';

	return temp;
}

String& String::operator+=(const String& rhs)
{
	const auto lhsSizeOffset = stringSize - 1;
	const auto rhsSize = rhs.stringSize - 1;
	const auto totalSize = lhsSizeOffset + rhsSize;

	String temp(totalSize + 1);
	
	for (auto i = 0; i < lhsSizeOffset; ++i)
	{
		temp.str[i] = str[i];
	}

	for (auto i = lhsSizeOffset, j = 0; i < totalSize; ++i, ++j)
	{
		temp.str[i] = rhs.str[j];
	}
	temp.str[totalSize] = '\0';

	*this = temp;

	return *this;
}

bool String::operator==(const String& rhs) const
{
	auto isEqual = true;
	const auto len1 = length();
	const auto len2 = rhs.length();
	
	if (len1 != len2)
	{
		isEqual = false;
		return isEqual;
	}


	for (auto i = 0; i < len1; ++i)
	{
		if (str[i] != rhs.str[i])
		{
			isEqual = false;
		}
	}

	//std::cout << "\n" << *this << " compare " << rhs << std::endl;
	return isEqual;
}

bool String::operator<(const String& rhs) const
{
	auto i = 0;
	while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) 
		++i;
	
	return str[i] < rhs.str[i];
}

String String::substr(int start, int end) const
{
	if (start < 0)
	{
		return *this;
	}
	if (start > end)
	{
		return String();
	}

	if (end >= length())
	{
		return *this;
	}

	String result;

	auto i = start;

	while (i <= end) {

		result += str[i];

		++i;

	}

	String* k = new String(result);

	return *k;
	
}

int String::findch(int start, char c) const
{
	if (start < 0)
		start = 0;
	if (start > stringSize - 1)
		return -1;

	const auto len = stringSize;
	for (auto i = start; i < len; i++)
	{
		if (str[i] == c)
			return i;
	}

	return -1;
}

int String::findstr(int start, const String& rhs) const
{

	if (start < 0)
		start = 0;

	if (start > length())
		return -1;

	if (length() < rhs.length())
		return -1;
	
	int i = start;

	while ((str[start] != 0) && (rhs.length() + start - 1 <= length()) && (i < stringSize)) 
	{

		if (rhs == substr(i, i + rhs.length() - 1))
		{
			return i;
		}

		++i;
	}
	
	return -1;
}



std::ostream& operator<<(std::ostream& out, const String& string)
{
	out << string.str;

	return out;
}

std::istream& operator>> (std::istream& in, String& newString)
{
	char temp[1000];
	
	in >> temp;
	
	newString = String(temp);
	
	return in;
}

String operator+(const char c[], const String& rhs)
{
	String lhs(c);

	lhs += rhs;

	return lhs;
}

String operator+(const char c, const String& rhs)
{
	String lhs(c);

	lhs += rhs;

	return lhs;
}

bool operator==(const char c[], const String& rhs)
{
	const String lhs(c);

	return (lhs == rhs);
}

bool operator==(const char c, const String& rhs)
{
	const String lhs(c);

	return (lhs == rhs);
}

bool operator<(const char c[], const String& rhs)
{
	const String lhs(c);

	return (lhs < rhs);
}

bool operator<(char c, const String& rhs)
{
	const String lhs(c);

	return (lhs < rhs);
}

bool operator<=(const String& lhs, const String& rhs)
{
	return (lhs < rhs) || (lhs == rhs);
}

bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}

bool operator>=(const String& lhs, const String& rhs)
{
	return (rhs <= lhs);
}

bool operator>(const String& lhs, const String& rhs)
{
	return !(lhs < rhs);
}

/*
int main()
{
	String s1("abc");
	String s2("def");
	String s3("dog");
	String s4("dog");
	String s5("d");
	String s6("ab");
	
	std::cout << "----------------------------" << std::endl;
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s2: " << s2 << std::endl;
	std::cout << "s1: " << s3 << std::endl;
	std::cout << "s2: " << s4 << std::endl;
	std::cout << "s1: " << s5 << std::endl;
	std::cout << "s2: " << s6 << std::endl;
	std::cout << "----------------------------" << std::endl;

	s1.swap(s2);
	std::cout << "----------------------------" << std::endl;
	std::cout << "s1 swap with s2" << std::endl;
	std::cout << "s1: " << s1 << std::endl;

	std::cout << "----------------------------" << std::endl;

	s1 = "abc";
	std::cout << "----------------------------" << std::endl;
	std::cout << "s1 = \"abc\""  << std::endl;
	std::cout << "s1: " << s1 << std::endl;

	std::cout << "----------------------------" << std::endl;

	s1 = s1 + s2;
	std::cout << "----------------------------" << std::endl;
	std::cout << "s1 = s1 + s2: "<< std::endl;
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "----------------------------" << std::endl;
	
	s1 += s2;
	std::cout << "----------------------------" << std::endl;
	std::cout << "s1 += s2: " << s1 << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << "----------------------------" << std::endl;
	std::cout << "s1 += s2: " << s1 << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << "----------------------------" << std::endl;
	if (s3 == s4)
	{
		std::cout << s3 << " == " << s4 << std::endl;
	}
	else
	{
		std::cout << s3 << " != " << s4 << std::endl;
	}
	
	if (s1 == s4)
	{
		std::cout << s1 << " == " << s4 << std::endl;
	}
	else
	{
		std::cout << s1 << " != " << s4 << std::endl;
	}
	std::cout << "----------------------------" << std::endl;

	std::cout << "----------------------------" << std::endl;
	if (s3 != s4)
	{
		std::cout << s3 << " != " << s4 << std::endl;
	}
	else
	{
		std::cout << s3 << " == " << s4 << std::endl;
	}

	if (s1 != s4)
	{
		std::cout << s1 << " != " << s4 << std::endl;
	}
	else
	{
		std::cout << s1 << " == " << s4 << std::endl;
	}
	std::cout << "----------------------------" << std::endl;
	
	std::cout << "----------------------------" << std::endl;
	if (s3 <= s4)
	{
		std::cout << s3 << " <= " << s4 << std::endl;
	}
	else
	{
		std::cout << s3 << " !<= " << s4 << std::endl;
	}

	if (s1 <= s4)
	{
		std::cout << s1 << " <= " << s4 << std::endl;
	}
	else
	{
		std::cout << s1 << " !<= " << s4 << std::endl;
	}
	std::cout << "----------------------------" << std::endl;

	std::cout << "----------------------------" << std::endl;
	if (s3 >= s4)
	{
		std::cout << s3 << " >= " << s4 << std::endl;
	}
	else
	{
		std::cout << s3 << " !>= " << s4 << std::endl;
	}

	if (s1 >= s4)
	{
		std::cout << s1 << " >= " << s4 << std::endl;
	}
	else
	{
		std::cout << s1 << " !>= " << s4 << std::endl;
	}
	std::cout << "----------------------------" << std::endl;

	std::cout << "----------------------------" << std::endl;
	if (s5 < s6)
	{
		std::cout << s5 << " < " << s6 << std::endl;
	}
	else
	{
		std::cout << s5 << " > " << s6 << std::endl;
	}

	if (s1 < s2)
	{
		std::cout << s1 << " < " << s2 << std::endl;
	}
	else
	{
		std::cout << s1 << " > " << s2 << std::endl;
	}
	std::cout << "----------------------------" << std::endl;

}
*/