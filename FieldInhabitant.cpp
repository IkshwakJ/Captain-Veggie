#include"FieldInhabitant.h"

FieldInhabintant::FieldInhabintant(string input_symbol)
{
    symbol = input_symbol;
}
string FieldInhabintant::getsymbol()
{
    return symbol;
}
void FieldInhabintant::setsymbol(string input_symbol)
{
    symbol = input_symbol;
}
FieldInhabintant::~FieldInhabintant()
{}