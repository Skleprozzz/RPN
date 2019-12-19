#include "RPN.h"
#include <stdio.h>

int main() {
	string expr = "15 3/11 + 3 5 * - 3.2 / 5.6 10 - *";
	vector<Lexema> lexStack;
	cout << "Expression  : " << expr.c_str() << endl;
	Parser parser;
	RPN rpn;
	lexStack = parser.parse(expr);
	double result = rpn.solve(lexStack);
	cout << "Answer      : " << result << endl << endl;
	getchar();
	return 0;
}