#pragma once
#include "Parser.h"
class RPN
{
public:
	RPN();
	~RPN();
	double solve(vector<Lexema> lexems);
};

