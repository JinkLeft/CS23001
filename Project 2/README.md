<h1>CS 23001 Computer Science II: Data Structures & Abstraction </h1>


<h1>Objectives:</h1>
-Use a well developed ADT class which utilizes operator overloading.
-Use dynamically allocated arrays.

<h1>Problem:</h1>
The Apache web server produces information detailing web page accesses, this information is stored in a log file in the Apache Common log file format. The assignment is to develop a program to process this log file and keep track of the different types of log entries.

<h1>Requirements:</h1>
You CANNOT use the C++ standard string or any other libraries for this assignment, except where specified.
You must use your ADT string for the later parts of the assignment.
using namespace std; is stricly forbiden. As are any global using statements.
Name the folder for this project: string (please use all lower case letters).

<h1>Milestone 1 (25pts)</h1>
<h2>Implementation:</h2>
Create an ADT String using the class construct. It will be a NULL (zero) terminating charater array.
Note: C++ has a standard type called string so you should not use this name. Use String instead.
Please name all your files using only lower case letters.
Use the provided specification (svn/shared/project2/string-mile1.hpp) for naming your class and methods You should rename this to string.hpp. A test suite will be provided in Part 2 that uses this interface to test your string class.
You should use a fixed sized array of char for storage with a max capacity based on a constant const int STRING_SIZE = 256; This array will store the characters along with the NULL (0) terminator.
Implement the constructor functions (i.e., for char[] and char).
Overload + and += as concatenation (make sure they works for all variations string + string, string + char[], char[] + string, etc).
Overload all the relational operators (==, <, >, etc.).
Implement the methods:
operator[](int) - both accessor and modifier versions
length() - returns number of characters in string
capacity() - returns the max number of characters that can be stored in the string
substr(int start, int end) - returns the sub string from start to end position (inclusive)
findch(int pos, char ch) - returns location of ch at or after pos, returns -1 if not found
findstr(int pos, cosnt String& str) - returns the location of str at or after pos, returns -1 if not found.
Overload both I/O operators - Input should read in one word at a time. The input operator for char[] works that way and can be used.

Testing:
Develop a set of test cases, using asserts, for each of the operators and methods of the String class.
Write test cases first. Testing must be thorough. You will be relying on the string to be correct.
The command make tests will build and run the unit tests.
After each function passes a test, commit your work to svn with a message such as "Constructor tests passed".
Your string class will be tested on a set of cases developed by the instructors. You will be graded on how well you pass the instructor tests. These tests cover the required constructors and operators.


<h1>Milestone 2 (25pts)</h1>
<h2>Implementation:</h2>
Re-implement your String class to use a dynamically allocated array for storage. Just as in the previous version, it will be a NULL terminating charater array.
Use the provided specification (svn/shared/project2/string-mile2.hpp) for naming your class and methods You should rename this to string.hpp.
This dynamic version of the String will only allocate exactly the amount of memory necessary to store the charaters. That is, the length will be the same as the capacity. However, the size of the dynamic array needs to have an extra char for the NULL terminator.
You will need to re-write your constructors to allocate the correct amount of memory.
The default constructor should allocate an array of size 1 for the empty string. The other constructors will allocate memory as needed. For example for String str("abc"); str.capacity() == 3, str.length() == 3, and str.stringSize == 4.
Implement a destructor, copy constructor, constant time swap, and assignment operator for your ADT. Also re-implement += to deal with the dynamic aspects.
You will also have to update concat/operator+() to return the proper sized string result.
Implement a private method resetCapacity to change the capacity of your string while keeping the contents intact. That is, create a new array and copy contents over to the new array, making sure to clean up memory.
Additionally, implement two private constructors that will be useful for managing memory. String(int) creates a String of capacity n and length 0. String(int, const char[]) creates a string of capacity n with an initial value of the char[] (and length equal to the char[]). Both of these constructors break the class invariant and thus are private for use by the class only.

Testing:
Re-run the tests you built from Milestone 1. Write additional tests for the methods (ctors, assign, etc.) developed for this milestone.
Write test cases first. Testing must be thorough. You will be relying on the String to be correct.
The command make tests will build and run the unit tests.
After each function passes a test, commit your work to svn with an appropriate message.
A testing oracle will also be provided. Run these using make oracle. These are a set of test cases for a large part of the string class functionality. You should make sure that the test cases you develop are as complete as the provided oracle.
You need to use the specification for String provided in string-mile2.hpp to take advantage of the test oracle.
The oracle tests pretty much all the constructors and operators in String.
If you add additional member variables to String, the tests will not work properly.
The command make oracle will build and run the unit tests.

<h1>Milestone 3 (25 pts)</h1>
<h2>Implementation:</h2>
You will use std::vector<> (need to include <vector>) for storing the results of parsing the input data.
For your String class, implement a method std::vector<String> String::split(char) const;
This method will return a vector of String split up based on a supplied character. For example:
s = "abc ef gh", then s.split(' ') returns a vector with three strings: { "abc", "ef", "gh" }
s = "-a--b-", then s.split('-') returns a vector with five strings: { "", "a", "", "b", "" }, three of which are empty string.

Testing:
Write additional test cases for your split method (test_split.cpp).
Make sure these tests demostrate that the method work properly.
The command make tests will build and run the unit tests.

<h1>Milestone 4 (25 pts)</h1>
<h2>Implementation:</h2>
See the supplied source code and data files in the shared folder in svn. logentry.cpp defines an ADT for logEntry. You will need to add functionality to this class (mainly constructors) to solve the problem. logview.cpp is the main and compiles and runs as is. You can modify this if needed.
For each line in the log file split the line on blanks. This should result in 10 strings.
If the entry is invalid (not 10 strings), store an empty ("", 0) logEntry.
For all valid entries you will need to do further processing and properly construct the logEntry data structure. See logentry.hpp

Testing:
Write a function (called parse) to read all the lines from the file and create a logEntry object for each line. This function will return a vector of logEntry's. See code in svn/shared/project2/
Write a function that given the vector of logEntry's computes the total number of bytes in all the entries.
Write a function that given the vector of logEntry's prints out the host member of each log entry (one per line).
Use the provided main that takes a file name and an option as command line parameters. The program will open the file name given on the command line and read from that file. Based on the command line options it will:
Print all the logEntry entries (neatly one per line).
Print the total number of bytes.
Print the host member for each logEntry (one per line).
The command make logview will build this program. Run it with ./logview option filename
Your program should work on all the provided input file(s).
Data file(s) are in svn/shared/project2/ log_1_tiny.txt, log_2_small.txt, and log3_medium.txt.
Additionally there is a VERY large data file (log_4_large.txt) at web.cs.kent.edu/~jmaletic/data/. Do NOT copy this into subversion as they it is very large. The direct path is /users/kent/jmaletic/public_html/data/log_4_large.txt
Other Requirements:
You must have a separate specification file (.hpp), implementation file (.cpp), and main file.
Your program will be graded on programming and commenting style as well as the implementation of your ADT.
Include all source code files in svn.
You can NOT use a pre-defined or built in class (other than std::vector) to solve this problem.
See the grading policy for other requirements.