#ifndef Snake_h
#define Snake_h
    #include"Creature.h"
    // This class is a subclass of the creature class, with no member variables of its own.
    class Snake:public Creature
    {
        public:
            //The constructor is to get the input for the creature class constructor.
            Snake(int input_heightpos, int input_widthpos);
    };
#endif