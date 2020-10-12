//File:        string-interface.hpp
//       
//Version:     1.0
//Date:        Fall 2019
//Author:      Dr. J. Maletic
//
//Description: Interface definition of String class for Project 2, milestone 1.
//
// To use the supplied test oracles you will need to use this interface and namings.
// You must also have all of these methods and functions defined for your string class.
//
// You will either have use this interface or call your methods through this interface.
//
// You need to implement all of the methods and functions declared here.
//

#ifndef CS23001_STRING_INTERFACE_HPP
#define CS23001_STRING_INTERFACE_HPP

#include <iostream>

const int STRING_SIZE = 256;                      //The size of the String.

////////////////////////////////////////////////////
// CLASS INV:   str[length()] == 0 &&
//              0 <= length() <= capacity() &&
//              capacity() == STRING_SIZE - 1
//
class String {
private:
    char str[STRING_SIZE];                          //STRING_SIZE is CONST

public:
    String();                                       //Empty string
	String(const char);                             //String('x')
    String(const char[]);                           //String("abcd")
	
    int capacity() const;                           //String.capacity() returns STRING_SIZE - 1
    int length() const;                             //String.length() returns length of String
    String substr(int, int ) const;
    int findChar(int, char);
    int findstr(int, const String&);
    char& operator[] (int);                         //Accessor/Modifier
    char operator[] (int) const;                    //Accessor
    String operator+ (const String&) const;         //Concatenation
    String operator+= (const String&);
    String operator+=(const char cArr[]);
    bool operator== (const String&) const;
    bool operator< (const String&) const;
    bool operator<= (const String&) const;
	
    friend std::istream& operator>>(std::istream&, String&);
    friend std::ostream& operator<<(std::ostream&, const String&);
};

String operator+ (const char[], const String&);
String operator+ (char, const String&);
bool operator== (const char[], const String&);
bool operator== (char, const String&);
bool operator< (const char[], const String&);
bool operator< (char, const String&);
bool operator!= (const String&, const String&);
bool operator>= (const String&, const String&);
bool operator> (const String&, const String&);

#endif
