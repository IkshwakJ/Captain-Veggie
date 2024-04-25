#include"Veggie.h"
// @brief The constructor of the Veggie class passes the required members to the constructor of the FieldInhabitant class.
// @param 1 string indicating the identity of the vegetable being stored.
// @param 2 string indicating what the vegetable should be indicated by, this parameter will be passed to the super class.
// @param 3 the point value the vegetable is worth.
Veggie::Veggie(string input_veg_type, string input_symbol, int input_pt_val):FieldInhabintant(input_symbol)
{
    veg_type = input_veg_type;
    pt_val = input_pt_val;
}
// @brief this getter funtion returns the vegetable type.
// @return the value stored in veg_type is returned as a string.
string Veggie::getveg_type()
{
    return veg_type;
}
// @brief this getter returns the points the vegetable is worth.
// @return the value stored in the member variable pr_val is returned as int.
int Veggie::getpt_val()
{
    return pt_val;
}
// @brief this setter function sets the identity of the vegetable being stored.
// @param the string input that will be stored in the member variable veg_type.
void Veggie::setveg_type(string input_veg_type)
{
    veg_type = input_veg_type;
}
// @brief this setter function sets the points that the vegetable is worth.
// @param the integer input that will be stored in the member variable pt_val.
void Veggie::setpt_val(int input_pt_val)
{
    pt_val = input_pt_val;
}