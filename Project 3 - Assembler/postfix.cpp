#include <fstream>
#include <vector>
#include "stack.hpp"
#include "string.hpp"
#include "utilities.hpp"

int main(int argc, char *argv[]){
	
	std::ifstream in (argv [1]);
	if ( !in.is_open() ){
		std::cout<<"Could not open file\n";
		return 1;
	}

	std::ofstream out(argv[2]);
	
    String currentToken;
	char token[300];
	
	while (!in.eof()){
		if(in.getline(token, 300, ';')) {
			
			currentToken = String(token);

				
			if(currentToken[0] == '\r'){
				int length = currentToken.length() - 1;
				currentToken = currentToken.substr(2,length);
			}

			
			String postfix = infix_to_postfix(currentToken);
		
			if(argc == 2) {
				if(currentToken.length() > 2) {
					std::cout << "Infix Expression: " << currentToken << std::endl;
					std::cout << "Postfix Expression: " << postfix << std::endl;
				}
			} else if (argc == 3) {
				if(currentToken.length() > 2) {
					out << "Infix Expression: "  << currentToken << std::endl;
					out << "Postfix Expression: " << postfix << std::endl;
				}
			}	
			
			std::cout << std::endl;
				
		}
	}
	
	in.close();
	out.close();
  
  return 0;
}