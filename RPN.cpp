#include "RPN.h"

RPN::RPN()
{
}


RPN::~RPN()
{
}

double RPN::solve(vector<Lexema> lexems) {
	Lexema resultLex(Type_Lexems::digit, 0.0);
	Lexema v1, v2;
	Lexema symbol;
	vector<Lexema> lexStack;
	vector<Lexema>::iterator it; 
	for (it = lexems.begin(); it != lexems.end(); it++) {
		symbol = *it;
	
		if (symbol.getType() == Type_Lexems::symbol) {
			v1 = lexStack.back();
			lexStack.pop_back();
			v2 = lexStack.back();
			lexStack.pop_back();
				if (symbol.getValue() == '+') {
					resultLex.setDecimal((v1.getDecimalValue() + v2.getDecimalValue()));
				}
				if (symbol.getValue() == '-') {
					resultLex.setDecimal(v2.getDecimalValue() - v1.getDecimalValue());
				}
				if (symbol.getValue() == '*') {
					resultLex.setDecimal((v1.getDecimalValue() * v2.getDecimalValue()));
				}
				if (symbol.getValue() == '/') {
					resultLex.setDecimal((v2.getDecimalValue() / v1.getDecimalValue()));
				}
	
			cout << "===============" << endl;
			cout << "result" << resultLex << endl;
			lexStack.push_back(resultLex);
		}
		else {
			lexStack.push_back(symbol);
		}
	}
	return lexStack.back().getDecimalValue();
}