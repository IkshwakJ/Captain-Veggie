/* Author: Archith J, Ikshwak Jinesh
Date: 5-2-2024
Description: Header file to define the Rabbit class and its functions.
*/

#ifndef Rabbit_h
#define Rabbit_h
    #include"Creature.h"
    // This class is a subclass of the creature class, with no member variables of its own.
    class Rabbit:public Creature
    {
        public:
            //The constructor is to get the input for the creature class constructor.
            Rabbit(int input_heightpos, int input_widthpos);
    };
#endif
