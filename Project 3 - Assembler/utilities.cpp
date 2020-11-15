#include <sstream>
#include <iostream>
#include <vector>
#include "utilities.hpp"
#include "string.hpp"
#include "stack.hpp"

String infix_to_postfix(String infix)
{
	stack<String> s;
	String lhs, rhs, op;
	std::vector<String> split = infix.split(' ');
	
	for (unsigned long i = 0; i < split.size(); ++i) {
		if (split.at(i) == ")") {
			rhs = s.pop();
			op = s.pop();
			lhs = s.pop();
			s.push(lhs + rhs + op);
		} else {
				if( split.at(i) != "("){
					s.push(split.at(i) + ' ');
				}
		}
	}
	
	return lhs + rhs + op;
}


void to_assembly(String postfix)
{
	stack<String> s;
	String lhs, rhs, op, tempNum, currentToken;
	int tempNumber = 1;
	std::vector<String> split = postfix.split(' ');
	
	for (unsigned long i = 0; i < split.size(); ++i) {
			currentToken = split.at(i);
		if (split.at(i) != "+" && split.at(i) != "-" && split.at(i) != "*" && split.at(i) != "/" ) {
			s.push(currentToken);
		} else {
			rhs = s.pop();
			lhs = s.pop();
			
			std::cout << "    LD   " << lhs << std::endl;

			op = assembly_operator(currentToken);
			std::cout << op << rhs << std::endl;

			tempNum = "TEMP" + int_to_string(tempNumber++);

			s.push(tempNum);

			std::cout << "    ST   " << tempNum << std::endl;

		}
	}
	std::cout << std::endl;
}

std::ostream& to_assembly(String postfix, std::ostream& out)
{
	stack<String> s;
	String lhs, rhs, op, tempNum, currentToken;
	int tempNumber = 1;
	std::vector<String> split = postfix.split(' ');
	
	for (unsigned long i = 0; i < split.size(); ++i) {
			currentToken = split.at(i);
		if (split.at(i) != "+" && split.at(i) != "-" && split.at(i) != "*" && split.at(i) != "/" ) {
			s.push(currentToken);
		} else {
			rhs = s.pop();
			lhs = s.pop();
			
			out << "    LD   " << lhs << std::endl;

			op = assembly_operator(currentToken);
			out << op << rhs << std::endl;

			tempNum = "TEMP" + int_to_string(tempNumber++);

			s.push(tempNum);

			out << "    ST   " << tempNum << std::endl;

		}
	}
	
	out << std::endl;
	
	return out;
}

String assembly_operator(const String& op)
{
	switch (op[0]) {
	case '+':
		return "    AD   ";
		break;
	case '-':
		return "    SB   ";
		break;
	case '*':
		return "    MU   ";
		break;
	case '/':
		return "    DV   ";
		break;
	default:
		return "    UNDEFINED   ";
	}
}

String int_to_string(int x)
{
	if (!x) {
		return "0";
	}

    String result;

	do {
		char temp = ((x % 10) + '0');
		result += temp;
		x /= 10;
	} while (x > 0);

	return result;
}