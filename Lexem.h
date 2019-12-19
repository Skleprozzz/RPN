#include <ostream>
using namespace std;

enum Type_Lexems { digit, symbol };

class Lexema {
private:
	Type_Lexems type;
	char value = NULL;
	double decimal = NULL;
public:
	Lexema();
	Lexema(const Lexema &l);
	Lexema(Type_Lexems type, char val);
	Lexema(Type_Lexems type, double dec);
	bool operator==(const Lexema &v) const;
	Lexema& operator=(const Lexema &v);
	Type_Lexems getType();
	char getValue();
	double getDecimalValue();
	void setDecimal(double dec);
	void setValue(char sym);
	friend ostream& operator <<(ostream &out, const Lexema &l);
	~Lexema();
};