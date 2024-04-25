#include"Captain.h"
    Captain::Captain(int input_heightpos, int input_widthpos):Creature(input_heightpos,input_widthpos, "\33[93mV\33[0m")
    {}
    void Captain::addveggie(Veggie* input_veggie)
    {
        veg_list.push_back(input_veggie);
    }
    void Captain::setveggie(Veggie* input_veggie,long long unsigned int position)
    {
        veg_list.at(position)->setsymbol(input_veggie->getsymbol());
        veg_list.at(position)->setveg_type(input_veggie->getveg_type());
        veg_list.at(position)->setpt_val(input_veggie->getpt_val());
    }
    Veggie * Captain::getveggie()
    {
        if(veg_list.size() != 0)
            return(veg_list.at(veg_list.size()-1));
        return nullptr;
    }

    void Captain::popveggie()
    {
        veg_list.pop_back();
    }

    void Captain::printallveggies()
    {
        for(long long unsigned int i = 0; i<veg_list.size(); i++)
        {
            cout<<veg_list[i]->getveg_type()<<endl;
        }
    }