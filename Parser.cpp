#include "Parser.h"

Parser::Parser()
{
}


Parser::~Parser()
{
	while (!lexVector.empty()) {
		lexVector.clear();
	}
	delete &lexVector;
}

bool Parser::isOp(char c) {
	//Check for operators.
	switch (c) {
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}

vector<Lexema> Parser::parse(string exp) {
	//exp.replace(exp.begin(), exp.end(), ' ');
	int i = 0;
	std::string tok = "";
	while (i < exp.length()) {
		//Skip white space
		while (isspace(exp[i])) {
			i++;
		}
		//Check for digits and .
		if (isdigit(exp[i]) | exp[i] == '.') {
			while (isdigit(exp[i]) | exp[i] == '.') {
				tok += exp[i];
				i++;
			}
			//Push on stack number.
			lexVector.push_back(Lexema(Type_Lexems::digit, atof(tok.c_str())));
			tok = "";
		}
		//Check for operator
		else if (isOp(exp[i]))
		{
			lexVector.push_back(Lexema(Type_Lexems::symbol, exp[i]));
		}
		else {
			cout << "Invaild exp." << endl;
			break;
		}
		i++;
	}
	return lexVector;
}