#ifndef Captain_h
#define Captain_h
    #include"Creature.h"
    #include"Veggie.h"
    //The Captain class is a subclass of the Creature class.
    class Captain:public Creature
    {
        private:
            //The veg_list member variable keeps track of the vegetables that the player has collected.
            vector<Veggie*> veg_list;
        public:
            //This is the contructor function thaat takes in input that is completely passed to the constructor of the Creature class.
            Captain(int input_heightpos, int input_widthpos);
            //This function adds a vegetable to the vector veg_list.
            void addveggie(Veggie * input_veggie);
            //This function modifies a vegetable at a given location on the veg_list.
            void setveggie(Veggie * input_veggie, long long unsigned int position);
            //This function returns the last vegetable on the veg_list.
            Veggie * getveggie();
            //This function removes the last vegetable on the veg_list.
            void popveggie();
            //This function prints all the vegetables on the list veg_list and removes all the vegetables on the list after printing.
            void printallveggies();
    };
#endif