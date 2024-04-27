#include"GameEngine.h"
void GameEngine::initialzeGame()
{
    initVeggies();
    initCaptain();
    score = 0;
    timer = 0;
}

void GameEngine::initVeggies()
{
    string filename, data_input, veggie_name, veggie_symbol;
    ifstream filestream;
    stringstream line_input;
    int veggie_point_value, height_rand, width_rand;
    long long unsigned int number_of_veggies = 0, veggie_rand;
    bool flag;
    do
    {
        cout<<"Please enter the name of the vegetable point file: ";
        cin>>filename;
        filestream.open(filename);
        if(!filestream.is_open())
        {
            cout<<filename<<" does not exist!"<<endl;    
        }
    }while(!filestream.is_open());
    while(!filestream.eof())
    {
        getline(filestream,data_input);
        line_input.clear();
        line_input.str(data_input);
        while(!line_input.eof())
        {
            getline(line_input, data_input, ',');
            if(data_input.compare("Field Size") == 0)
            {
                getline(line_input, data_input, ',');
                height = stoi(data_input);
                getline(line_input, data_input, ',');
                width = stoi(data_input);
            }
            else
            {
                veggie_name = data_input;
                getline(line_input, data_input, ',');
                veggie_symbol = data_input;
                getline(line_input, data_input, ',');
                veggie_point_value = stoi(data_input);
                Veggie* temp = new Veggie(veggie_name,veggie_symbol,veggie_point_value);
                possible_veggie.push_back(temp);
                number_of_veggies++;
            }
            
        }
    }
    // The file has been closed.
    filestream.close();
    line_input.clear();

    field = new FieldInhabintant**[height];
    for(int i = 0; i<height; i++)
    {
        field[i] = new FieldInhabintant*[width];
        for(int j = 0; j<width; j++)
        {
            field[i][j] = nullptr;
        }
    }
    //Please note that NUMBEROFVEGGIES is the limit set to fill the field with veggies since the initveggies will only be called once at the begining of the game.
    for(int i = 0; i<NUMBEROFVEGGIES; i++)
    {
        if(height*width < NUMBEROFVEGGIES)
        {
            cout<<"Field size is below game requirements!"<<endl;
            exit(0);
        }
        veggie_rand = (long long unsigned int)rand()%number_of_veggies;
        veggie_name = possible_veggie[veggie_rand]->getveg_type();
        veggie_symbol = possible_veggie[veggie_rand]->getsymbol();
        veggie_point_value = possible_veggie[veggie_rand]->getpt_val();
        do
        {
            flag = true;
            height_rand = rand()%height;
            width_rand = rand()%width;
            if(field[height_rand][width_rand] != nullptr)
            {
                flag = false;
            }
            else
            {
                field[height_rand][width_rand] = new Veggie(veggie_name, veggie_symbol, veggie_point_value);
            }
        }while(flag == false);
    }
    printField();
}

void GameEngine::initCaptain()
{
    int capheightpos, capwidthpos;
    bool flag;
    do 
    {
        flag = true;
        capheightpos = rand()%height;
        capwidthpos = rand()%height;
        if(field[capheightpos][capwidthpos] != nullptr)
        {
            flag = false;
        }
        else
        {
            field[capheightpos][capwidthpos] = new Captain(capheightpos,capwidthpos);
        }
        player = new Captain(capheightpos,capwidthpos);
    }
    while(flag == false);
}