/**
 * David Russell
 * String
 * CS 23001
 * Creating our own implementation of the string ADT
*/
#include "string.hpp"

String::String()
{
	str[0] = '\0';
}

String::String(const char c)
{
	str[0] = c;
	str[1] = '\0';
}

String::String(const char cArr[])
{
	auto i = 0;

	for (i = 0; i < STRING_SIZE; ++i)
	{
		str[i] = cArr[i];

		if (cArr[i] == '\0')
		{
			break;
		}
	}

	str[i] = '\0';
}

int String::capacity() const
{
	return STRING_SIZE - 1;
}

int String::length() const
{
	int i;

	for (i = 0; i < STRING_SIZE; i++)
	{
		if (str[i] == '\0')
		{
			break;
		}
	}

	return i;
}

String String::substr(int start, int end) const
{
	if (start < 0)
		start = 0;
	if (start > length())
		return String();
	if (start > end)
		return String();
	if (end >= length())
		end = length() - 1;

	String rlt;
	int i;

	for (i = start; i <= end; i++)
	{
		rlt.str[i - start] = str[i];
	}

	rlt.str[i - start] = '\0';

	return rlt;
}

int String::findChar(int start, char c)
{
	if (start < 0)
		start = 0;
	if (start > length() - 1)
		return -1;

	const auto len = length();
	for (auto i = start; i < len; i++)
	{
		if (str[i] == c)
			return i;
	}

	return -1;
}

int String::findstr(int start, const String& rhs)
{
	if (start < 0)
		start = 0;
	if (start > length() - 1)
		return -1;
	
	const auto rhsLength = rhs.length();
	const auto lhsLength = length();
	
	for (auto i = 0; i < lhsLength; ++i)
	{
		String temp;
		
		if ((start + i) <= lhsLength)
		{
			temp = this->substr(start + i, rhsLength + i - 1);
		}
		
		if (temp == rhs)
		{

			return i;
		}
	}

	return -1;
}

char& String::operator[](const int index)
{
	return str[index];
}

char String::operator[](const int index) const
{
	return str[index];
}

String String::operator+(const String& rhs) const
{
	String temp;
	const auto rhsLength = rhs.length();
	const auto lhsLength = length();

	for (auto i = 0; i < lhsLength; ++i)
	{
		temp.str[i] = str[i];
	}

	for (auto i = lhsLength, j = 0; i < STRING_SIZE - 2; ++i, ++j)
	{
		temp.str[i] = rhs.str[j];
	}

	const auto totalLength = (rhsLength + lhsLength);

	if (totalLength < (STRING_SIZE - 1))
	{
		temp.str[totalLength] = '\0';
	}
	else if (totalLength > (STRING_SIZE - 1) || totalLength == (STRING_SIZE - 1))
	{
		temp.str[STRING_SIZE - 1] = '\0';
	}

	return temp;
}

String String::operator+=(const String& rhs)
{
	String temp;
	const auto rhsLength = rhs.length();
	const auto lhsLength = length();

	for (auto i = 0; i < lhsLength; ++i)
	{
		temp.str[i] = str[i];
	}

	for (auto i = lhsLength, j = 0; i < STRING_SIZE - 2; ++i, ++j)
	{
		temp.str[i] = rhs.str[j];
	}

	const auto totalLength = (rhsLength + lhsLength);

	if (totalLength < (STRING_SIZE - 1))
	{
		temp.str[totalLength] = '\0';
	}
	else if (totalLength > (STRING_SIZE - 1) || totalLength == (STRING_SIZE - 1))
	{
		temp.str[STRING_SIZE - 1] = '\0';
	}
	
	*this = temp;
	
	return *this;
}

String String::operator+=(const char cArr[])
{
	String rhs = cArr;
	*this = *this + rhs;
	return *this;
}

bool String::operator==(const String& str2) const
{
	auto isEqual = true;
	const auto len1 = length();
	const auto len2 = str2.length();

	if (len1 != len2)
	{
		isEqual = false;
		return isEqual;
	}


	for (auto i = 0; i < len1; ++i)
	{
		if (str[i] != str2.str[i])
		{
			isEqual = false;
		}
	}

	
	return isEqual;
}

bool String::operator<(const String& str2) const
{
	return (*this <= str2 && !(*this == str2));
}

bool String::operator<=(const String& str2) const
{
	const auto len1 = length();
	const auto len2 = str2.length();

	if (len1 > len2)
		return false;

	for (auto i = 0; i <= len2 - len1; i++)
	{
		if (substr(i, i + len2 - 1) == (*this))
			return true;
	}

	return false;
}

std::istream& operator>>(std::istream& in, String& s)
{
	/* COMMENTED OUT UNTIL CLARIFICATION FOR HOW THE ASSIGNMENT SHOULD BE DONE
	char c;
	auto i = 0;

	while (!in.eof())
	{
		in >> c;
		if (c == '\n' || c == '\0' || c == ';')
		{
			break;
		}
		s.str[i] = c;
		i++;
	}

	s.str[i] = '\0';
	*/
	
	char temp[STRING_SIZE];
	in >> temp;
	if (s.length() == 0)
	{
		s = String(temp);
	}
	else
	{
		s = s + String(temp);
	}
	
	return in;
}

std::ostream& operator<<(std::ostream& out, const String& s)
{
	out << s.str;
	return out;
}

String operator+(const char cArr[], const String& rhs)
{
	return String(cArr) + rhs;
}

String operator+(char c, const String& rhs)
{
	return String(c) + rhs;
}

bool operator== (const char cArr[], const String& rhs)
{
	auto lhs = String(cArr);
	auto isEqual = true;

	if (lhs.length() != rhs.length())
	{
		isEqual = false;
		return isEqual;
	}

	for (auto i = 0; i < lhs.length(); ++i)
	{
		if (lhs[i] != rhs[i])
		{
			isEqual = false;
		}
	}

	return isEqual;
}

bool operator== (const char c, const String& rhs)
{
	auto lhs = String(c);
	auto isEqual = true;

	if (lhs.length() != rhs.length())
	{
		isEqual = false;
		return isEqual;
	}

	for (auto i = 0; i < lhs.length(); ++i)
	{
		if (lhs[i] != rhs[i])
		{
			isEqual = false;
		}
	}

	return isEqual;
}

bool operator< (const char cArr[], const String& rhs)
{
	const auto lhs = String(cArr);

	return !(lhs > rhs);
}


bool operator< (char c, const String& rhs)
{
	const auto lhs = String(c);

	return !(lhs > rhs);
}

bool operator!= (const String& lhs, const String& rhs)
{
	if(lhs == rhs)
	{
		return false;
	}
	else
	{
		return true;
	}
}


bool operator>= (const String& lhs, const String& rhs)
{
	if(lhs > rhs || lhs == rhs)
	{
		return true;
	}

	return false;
}

bool operator> (const String& lhs, const String& rhs)
{
	auto totalL = 0;
	auto totalR = 0;
	const auto lhsLength = lhs.length();
	const auto rhsLength = rhs.length();

	for(auto i = 0; i < lhsLength; ++i)
	{
		totalL += static_cast<int>(lhs[i]);
		if(lhs[i] == '\0')
		{
			break;
		}
	}

	for(auto i = 0; i < rhsLength; ++i)
	{
		totalR += static_cast<int>(rhs[i]);
		if(rhs[i] == '\0')
		{
			break;
		}
	}
	
	if (totalL > totalR)
		return true;
	else
		return false;

}

/*
int main()
{
	const String s1("");
	String s2("abc");
	String s3("");
	char cAr[] = "abc";
	const auto c = 'a';
	String s4 = "dog";
	s4 += "a";
	
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s4 << std::endl;

	//std::cin >> s2;
	std::cout << s2 << std::endl;

	if (s1 > s2)
	{
		std::cout << "\n s1 > s2" << std::endl;
	}
	else
	{
		std::cout << "\n s1 < s2" << std::endl;
	}
	
	if (cAr != s2)
	{
		std::cout << "\n cAr != s2" << std::endl;
	}
	else
	{
		std::cout << "\n cAr == s2" << std::endl;
	}
	
	if (s1 != s2)
	{
		std::cout << "\n s1 != s2" << std::endl;
	}
	else
	{
		std::cout << "\n s1 == s2" << std::endl;
	}

	if (c == s1)
	{
		std::cout << "\n c == s1" << std::endl;
	}
	else
	{
		std::cout << "\n c != s1" << std::endl;
	}

	if (s3 == s1)
	{
		std::cout << "\n s3 == s1" << std::endl;
	}
	else
	{
		std::cout << "\n s3 != s1" << std::endl;
	}
}
*/