#include"FieldInhabitant.h"
// @brief constructor, enters the passed string to member variable.
// @param string input.
FieldInhabintant::FieldInhabintant(string input_symbol)
{
    symbol = input_symbol;
}
// @brief returns the member varable symbol.
// @return stored value in symbol variable as string.
string FieldInhabintant::getsymbol()
{
    return symbol;
}
// @brief Updates the member variable using the passed string.
void FieldInhabintant::setsymbol(string input_symbol)
{
    symbol = input_symbol;
}
// @brief destructor is virtual and has no function.
FieldInhabintant::~FieldInhabintant()
{}