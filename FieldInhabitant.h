/* Author: Archith J, Ikshwak Jinesh
Date: 5-2-2024
Description: Header file to define the FieldInhabintant class and its functions.
*/

#ifndef FieldInhabitant_h
#define FieldInhabitant_h
    #include<iostream>
    #include<fstream>
    #include<vector>
    #include<sstream>
    #include<cstdlib>
    using namespace std;

    //The superclass for all other classes in the Project
    class FieldInhabintant
    {
        private:
            //Symbol that will be printed onto the screen as the game is played.
            string symbol; 
        public:
            //constructor
            FieldInhabintant(string input_symbol);
            //getter
            string getsymbol();
            //setter
            void setsymbol(string input_symbol);
            //destructor 
            virtual ~FieldInhabintant();
    };
#endif
