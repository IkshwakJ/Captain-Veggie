/* Author: Archith J, Ikshwak Jinesh
Date: 5-2-2024
Description: Program defining the Rabbit class functions.
*/

#include"Rabbit.h"
// @brief This constructor function takes in input an pass them to the constructor of the creature class, along with the symbol for the Rabbit.
// @param 1 input_heightpos is an integer representing the rabbits vertical position on the map.
// @param 2 input_widthpos is an integer representing the rabbits horizontal position on the map.
Rabbit::Rabbit(int input_heightpos, int input_widthpos):Creature(input_heightpos, input_widthpos, "\33[96mR\33[0m")
{}
