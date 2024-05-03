/* Author: Archith J, Ikshwak Jinesh
Date: 5-2-2024
Description: Program defining the Snake class functions.
*/

#include"Snake.h"
// @brief This constructor function takes in input an pass them to the constructor of the creature class, along with the symbol for the Snake.
// @param 1 input_heightpos is an integer representing the snakes vertical position on the map.
// @param 2 input_widthpos is an integer representing the snakes horizontal position on the map.
Snake::Snake(int input_heightpos, int input_widthpos ):Creature(input_heightpos, input_widthpos,"\33[91mS\33[0m")
{}
