#ifndef FieldInhabitant_h
#define FieldInhabitant_h
    // TODO transfer headers to main
    #include<iostream>
    #include<fstream>
    #include<vector>
    #include<sstream>
    #include<cstdlib>
    using namespace std;
    class FieldInhabintant
    {
        private:
            string symbol; 
        public:
            FieldInhabintant(string input_symbol);
            string getsymbol();
            void setsymbol(string input_symbol);
            virtual ~FieldInhabintant();
    };

#endif