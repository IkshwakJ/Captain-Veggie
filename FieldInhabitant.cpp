/* Author: Archith J, Ikshwak Jinesh
Date: 5-2-2024
Description: Program defining the functions of the FieldInhabintant class.
*/

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
// @param 1 input_symbol is a string input that will be stored in the symbol variable.
void FieldInhabintant::setsymbol(string input_symbol)
{
    symbol = input_symbol;
}
// @brief destructor is virtual and has no function.
FieldInhabintant::~FieldInhabintant()
{}
