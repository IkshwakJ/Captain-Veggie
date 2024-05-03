/* Author: Archith J, Ikshwak Jinesh
Date: 5-2-2024
Description: Program defning the functions declared in the Creature class.
*/

#include"Creature.h"
// @brief Contructor for the creature class
// @param 1 integer input that indicates the vertical position of the creature.
// @param 2 integer input that indicates the horizontal position of the creature.
// @param 3 string input that indicates the symbol of the creature and will be passed to the constructor of FieldInhabitant.
Creature::Creature(int input_heightpos, int input_widthpos, string input_symbol):FieldInhabintant(input_symbol)
{
    heightpos = input_heightpos;
    widthpos = input_widthpos;
}
// @brief getter function to return the vertical position of the creature.
// @return the value stored in member variable heightpos as integer.
int Creature::getheightpos()
{
    return heightpos;
}
// @brief getter function to return the horizontal position of the creature.
// @return the value stored in member variable widthpos as integer.
int Creature::getwidthpos()
{
    return widthpos;
}
// @brief setter function that enters the passed integer into the heightpos member variable.
// @param integer value that is to be stored in the heightpos member variable.
void Creature::setheightpos(int input_heightpos)
{
    heightpos = input_heightpos;
}
// @brief setter function that enters the passed integer into the widthpos member variable.
// @param integer value that is to be stored in the widthpos member variable.
void Creature::setwidthpos(int input_widthpos)
{
    widthpos = input_widthpos;
}
