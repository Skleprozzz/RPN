#include "Lexem.h"
#include <iostream>

Lexema::Lexema(Type_Lexems type, char val)
{
	this->type = Type_Lexems::symbol;
	this->setValue(val);
}

Lexema::~Lexema() {};

Lexema::Lexema(Type_Lexems type, double val)
{
	this->type = Type_Lexems::digit;
	this->setDecimal(val);
}

Lexema::Lexema() {

}

Lexema::Lexema(const Lexema &l) {
	this->type = l.type;
	this->decimal = l.decimal;
	this->value = l.value;
}


void Lexema::setValue(char sym) {
	this->value = sym;
}

void Lexema::setDecimal(double sym) {
	decimal = sym;
}

double Lexema::getDecimalValue() {
	return this->decimal;
}

char Lexema::getValue() {
		return this->value;
};

Type_Lexems Lexema::getType() {
	return this->type;
};

ostream& operator<<(ostream &out, const Lexema &l) {
	out << "Type: " << l.type << "\n" << "Decimal: " << l.decimal << " Value:" << l.value;
	return out;
};

bool Lexema::operator==(const Lexema &v) const {
	if (this->type == v.type) {
		if (this->type == Type_Lexems::symbol)
			return	this->value == v.value;
		else
			return this->decimal == this->decimal;
		
	}
	else
		return false;

};

Lexema& Lexema::operator=(const Lexema &v) {
	if (&v == this)
		return *this;
	this->type = v.type;
	this->decimal = v.decimal;
	this->value = v.value;
	return *this;

};
