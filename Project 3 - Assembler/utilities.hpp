#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H
#include "string.hpp"
#include "stack.hpp"

String infix_to_postfix(String infix);
void to_assembly(String infix);
std::ostream& to_assembly(String infix, std::ostream& out);
String assembly_operator(const String& op);
String int_to_string(int x);
String evaluate(String lhs, String token, String rhs);


#endif