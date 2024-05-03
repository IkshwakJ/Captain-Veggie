/* Author: Archith J, Ikshwak Jinesh
Date: 5-2-2024
Description: Program defining the functions declared in the Captain class.
*/

#include"Captain.h"

    // @brief This is the contructor function thaat takes in input that is completely passed to the constructor of the Creature class along with the symbol for the Captain.
    // @param 1 input_heightpos is an integer representing the captain's vertical position on the map.
    // @param 2 input_widthpos is an integer representing the captain's horizontal position on the map.
    Captain::Captain(int input_heightpos, int input_widthpos):Creature(input_heightpos,input_widthpos, "\33[93mV\33[0m")
    {}

    // @brief This function adds a veggie pointer pointing to the collected vegetbale to the list veg_list.
    // @param 1 input_veggie is a Veggie pointer that is to be added to the list veg_list.
    void Captain::addveggie(Veggie* input_veggie)
    {
        veg_list.push_back(input_veggie);
    }

    // @brief This function changes the values stored in the passed veggie pointer to the veggie pointer in the veg_list vector at the passed location.
    // @param 1 input_veggie is a veggie pointer passed to the function that is to be stored in a member of the veg_list vector.
    // @param 2 position is a long long unstigned integer variable that specifies the location in the veg_list that the modification is to be made at. 
    void Captain::setveggie(Veggie* input_veggie,long long unsigned int position)
    {
        veg_list.at(position)->setsymbol(input_veggie->getsymbol());
        veg_list.at(position)->setveg_type(input_veggie->getveg_type());
        veg_list.at(position)->setpt_val(input_veggie->getpt_val());
    }

    // @brief This function returns the last vegetable pointer in the veg_list.
    Veggie * Captain::getveggie()
    {
        if(veg_list.size() != 0)
            return(veg_list.at(veg_list.size()-1));
        return nullptr;
    }

    // @brief This function deletes the last member of the veg_list vector.
    void Captain::popveggie()
    {
        veg_list.pop_back();
    }

    // @brief This function prints all the vegetables in the veg_list in order and deletes all the members after prtinting the list.
    void Captain::printallveggies()
    {
        long long unsigned int size = veg_list.size();
        for(long long unsigned int i = 0; i<size; i++)
        {
            cout<<veg_list[i]->getveg_type()<<endl;
        }
        for(long long unsigned int i = 0; i<size; i++)
        {
            veg_list.pop_back();
        }
}
