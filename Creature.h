/* Author: Archith J, Ikshwak Jinesh
Date: 5-2-2024
Description: Header file to define the Creature class and its functions.
*/

#ifndef Creature_h
#define Creature_h
    #include"FieldInhabitant.h"
    // Creature class inherits from the FieldInhabitant class.
    class Creature:public FieldInhabintant
    {
        private:
            //The member variables store the position of the creature on the field.
            int heightpos, widthpos;
        public:
            //constructor for the Creature class.
            Creature(int input_heightpos, int input_widthpos, string input_symbol);
            //getter for vertical position.
            int getheightpos();
            //getter for vertical position.
            int getwidthpos();
            //setter for horizontal position. 
            void setheightpos(int input_heightpos);
            //setter for horizontal position.
            void setwidthpos(int input_widthpos);
    };
#endif
