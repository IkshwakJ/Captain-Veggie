#ifndef Veggie_h
#define Veggie_h
    #include"FieldInhabitant.h"
    // The Veggie class inherits from FieldInhabitant class.
    class Veggie:public FieldInhabintant
    {
        private:
            //The member variables store the type of vegetable it stores as a string and the points it gives as integer.
            string veg_type;
            int pt_val;
        public:
            // The constructor for Veggie class.
            Veggie(string input_veg_type, string input_symbol, int input_pt_val);
            // getter for veg_type.
            string getveg_type();
            // getter for pt_val.
            int getpt_val();
            //setter for veg_type.
            void setveg_type(string input_veg_type);
            //setter for pt_val.
            void setpt_val(int input_pt_val);
    };
#endif