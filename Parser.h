#include <iostream>
#include <vector>
#include <string>
#include "Lexem.h"
class Parser
{
public:
	Parser();
	~Parser();
	std::vector<Lexema> parse(std::string str);
private:
	std::vector<Lexema> lexVector;
	bool isOp(char c);
};

