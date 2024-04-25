#ifndef Captain_h
#define Captain_h
    #include"Creature.h"
    #include"Veggie.h"
    class Captain:public Creature
    {
        private:
            vector<Veggie*> veg_list;
        public:
            Captain(int input_heightpos, int input_widthpos);
            void addveggie(Veggie * input_veggie);
            void setveggie(Veggie * input_veggie, long long unsigned int position);
            Veggie * getveggie();
            void popveggie();
            void printallveggies();
    };
#endif