#include"GameEngine.h"
// @brief This function intializes the vegetables and creates a Captain variable for the player, it sets the score and timer to zero.
void GameEngine::initialzeGame()
{
    initVeggies();
    initCaptain();
    score = 0;
    timer = 0;
}

// @brief This function reads a file that the user specifies to create a field of the size defined in the file, and fills it with random vegetables. 
void GameEngine::initVeggies()
{
    string filename, data_input, veggie_name, veggie_symbol;
    ifstream filestream;
    stringstream line_input;
    int veggie_point_value, height_rand, width_rand;
    long long unsigned int number_of_veggies = 0, veggie_rand;
    bool flag;
    //Loop to open a file specified by the user.
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

    //Reading file to create a field and set up the possible vegetables that can fill the field.
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
    //The file has been closed.
    filestream.close();
    line_input.clear();

    //Creating the field.
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
    //The following function prints the field onto the terminal.
    printField();
}

// @brief This function creates a Captain variable for the player and places the player randomly on the field.
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

// @brief Creates one Rabbit and adds it to the vector of Rabbits and adds it to the field at a random position.
void GameEngine::spawnRabbits()
{
    int spawnheight, spawnwidth;
    if( int(rabbits_on_field.size())<MAXNUMBEROFRABBITS)
    {
        bool spawn_one_rabbit = false;
        do
        {
            spawnheight = rand()%height;
            spawnwidth = rand()%width;    
            if(field[spawnheight][spawnwidth] == nullptr)
            {
                Rabbit* temp = new Rabbit(spawnheight, spawnwidth);
                rabbits_on_field.push_back(temp);
                field[spawnheight][spawnwidth] = new Rabbit(spawnheight,spawnwidth);
                spawn_one_rabbit = true;
            }
        }while(!spawn_one_rabbit);
    }
}

// @brief This function counts the number of vegetables on the field.
// @return the number of vegetables on the field as an integer.
int GameEngine::remainingVeggies()
{
    int count_veggies_on_field = 0;
    for(int i = 0; i<height; i++)
    {
        for(int j = 0; j<width; j++)
        {
            if(dynamic_cast<Veggie*>(field[i][j]))
            {
                count_veggies_on_field++;
            }
        }
    }
    return count_veggies_on_field;
}

// @brief This function introduces the player to the game and shows the possible points for each catch and what the snake does.
void GameEngine::intro()
{
    cout<<"Welcome to Captain Veggie!"<<endl;
    cout<<"The rabbits are invading your garden and you must harvest"<<endl;
    cout<<"as many vegetables as possible before the rabbits eat them"<<endl;
    cout<<"all! Each vegetable is worth a different number of points"<<endl;
    cout<<"so go for the high score!"<<endl;
    cout<<"\nThe vegetables are: "<<endl;

    for(long long unsigned int i = 0; i<possible_veggie.size(); i++)    
    {
        cout<<possible_veggie[i]->getsymbol()<<": "<<possible_veggie[i]->getveg_type()<<", "<<possible_veggie[i]->getpt_val()<<endl;
    }
    cout<<"\nCaptain Veggie is V, and the rabbits are R's.\n"<<endl;
    cout<<"Catching a rabbit is worth 5 points, but more are"<<endl;
    cout<<"always on the way!\n"<<endl;
    // cout<<"Make sure to watch out for the snake on the field!"<<endl;
    // cout<<"The snake is S, it eats the rabbits, if it eats a rabbit it rests for 5 clock ticks."<<endl;
    // cout<<"and is trying to bite you!"<<endl;
    // cout<<"If you are bitten you will lose the newest 5 vegetables!\n"<<endl;
    cout<<"Good Luck!\n"<<endl;
}

// @brief This function prints the field and the characters that fill the field.
void GameEngine::printField()
{
    cout<<"\33[34m#\33[0m";
    for(int j = 0; j<width; j++)
    {
        cout<<"\33[34m###\33[0m";
    }
    cout<<"\33[34m#\33[0m"<<endl;
    for(int i = 0; i<height; i++)
    {
        cout<<"\33[34m#\33[0m";
        for(int j = 0; j<width; j++)
        {
            if(field[i][j]!=nullptr)
            {
                cout<<" "<<field[i][j]->getsymbol()<<" ";
            }
            else
            {
                cout<<"   ";
            }
        }
        cout<<"\33[34m#\33[0m"<<endl;
    }
    cout<<"\33[34m#\33[0m";
    for(int j = 0; j<width; j++)
    {
        cout<<"\33[34m###\33[0m";
    }
    cout<<"\33[34m#\33[0m"<<endl;
}

// @brief This function returns the score that the player gained.
int GameEngine::getScore()
{
    return score;
}

// @brief This function increments the clock by 1 and spawns a rabbit if the number of rabbits on the field is less than MAXNUMBEROFRABBITS. 
void GameEngine::timerTick()
{
    // The rabbits are spawned every 5 cycles.
    if(timer%5 == 0)
    {
        if(int(rabbits_on_field.size())<MAXNUMBEROFRABBITS)
        {
            cout<<"Oh no! Here comes another rabbit!"<<endl;
        }
        spawnRabbits();
    }
    timer++;    
}

// @brief This function moves the rabbits randomly and removes the vegetables if a rabbit lands on them.
void GameEngine::moveRabbits()
{
    long long unsigned int bunny_count = rabbits_on_field.size();
    int direction; //there are 8 directions to travel in. The 12 o'clock direction is 0 is incremented in the clockwise direction.
    int bunnyheight, bunnywidth, new_h, new_w;
    bool bunny_move = false;//to check if the bunny can move in an empty map within bounds.
    for(long long unsigned int i = 0; i<bunny_count; i++)
    {
        bunny_move = false;
        direction = rand()%8;
        bunnyheight = rabbits_on_field[i]->getheightpos();
        bunnywidth = rabbits_on_field[i]->getwidthpos();
        switch(direction)
        {
            case 0:
                if(bunnyheight != 0)
                {
                    bunny_move = true;
                    new_h = bunnyheight-1;
                    new_w = bunnywidth;
                }
                break;
            case 1:
                if(bunnyheight != 0 && bunnywidth != width-1)
                {
                    bunny_move = true;
                    new_h = bunnyheight-1;
                    new_w = bunnywidth+1;                   
                }
                break;
            case 2:
                if(bunnywidth != width-1)
                {
                    bunny_move = true; 
                    new_h = bunnyheight;
                    new_w = bunnywidth+1;                 
                }
                break;
            case 3:
                if(bunnyheight != height-1 && bunnywidth != width-1)
                {
                    bunny_move = true;
                    new_h = bunnyheight+1;
                    new_w = bunnywidth+1;
                }
                break;
            case 4:
                if(bunnyheight != height-1)
                {
                    bunny_move = true;
                    new_h = bunnyheight+1;
                    new_w = bunnywidth;
                }
                break;
            case 5:
                if(bunnyheight != height-1 && bunnywidth != 0)
                {
                    bunny_move = true;
                    new_h = bunnyheight+1;
                    new_w = bunnywidth-1;
                }
                break;
            case 6:
                if(bunnywidth != 0)
                {
                    bunny_move = true;
                    new_h = bunnyheight;
                    new_w = bunnywidth-1;
                }
                break;
            case 7:
                if(bunnyheight != 0 && bunnywidth != 0)
                {
                    bunny_move = true;
                    new_h = bunnyheight-1;
                    new_w = bunnywidth-1;
                }
                break;
        }
        if(bunny_move)
        {
            if(field[new_h][new_w] == nullptr)
            {
                field[new_h][new_w] = new Rabbit(new_h,new_w);
                rabbits_on_field[i]->setheightpos(new_h);
                rabbits_on_field[i]->setwidthpos(new_w);
                delete field[bunnyheight][bunnywidth];
                field[bunnyheight][bunnywidth] = nullptr;
            }
            else if((dynamic_cast<Veggie*>(field[new_h][new_w])))
            {
                delete field[new_h][new_w];
                field[new_h][new_w] = nullptr;
                field[new_h][new_w] = new Rabbit(new_h,new_w);
                rabbits_on_field[i]->setheightpos(new_h);
                rabbits_on_field[i]->setwidthpos(new_w);
                delete field[bunnyheight][bunnywidth];
                field[bunnyheight][bunnywidth] = nullptr;
            }
            else
            {
                bunny_move = false;
            }
        }
    }
 }

void GameEngine::spawnRabbits()
{
    int spawnheight, spawnwidth;
    if( int(rabbits_on_field.size())<MAXNUMBEROFRABBITS)
    {
        bool spawn_one_rabbit = false;
        do
        {
            spawnheight = rand()%height;
            spawnwidth = rand()%width;    
            if(field[spawnheight][spawnwidth] == nullptr)
            {
                Rabbit* temp = new Rabbit(spawnheight, spawnwidth);
                rabbits_on_field.push_back(temp);
                field[spawnheight][spawnwidth] = new Rabbit(spawnheight,spawnwidth);
                spawn_one_rabbit = true;
            }
        }while(!spawn_one_rabbit);
    }
}

int GameEngine::remainingVeggies()
{
    int count_veggies_on_field = 0;
    for(int i = 0; i<height; i++)
    {
        for(int j = 0; j<width; j++)
        {
            if(dynamic_cast<Veggie*>(field[i][j]))
            {
                count_veggies_on_field++;
            }
        }
    }
    return count_veggies_on_field;
}

void GameEngine::intro()
{
    cout<<"Welcome to Captain Veggie!"<<endl;
    cout<<"The rabbits are invading your garden and you must harvest"<<endl;
    cout<<"as many vegetables as possible before the rabbits eat them"<<endl;
    cout<<"all! Each vegetable is worth a different number of points"<<endl;
    cout<<"so go for the high score!"<<endl;
    cout<<"\nThe vegetables are: "<<endl;

    for(long long unsigned int i = 0; i<possible_veggie.size(); i++)    
    {
        cout<<possible_veggie[i]->getsymbol()<<": "<<possible_veggie[i]->getveg_type()<<", "<<possible_veggie[i]->getpt_val()<<endl;
    }
    cout<<"\nCaptain Veggie is V, and the rabbits are R's.\n"<<endl;
    cout<<"Catching a rabbit is worth 5 points, but more are"<<endl;
    cout<<"always on the way!\n"<<endl;
    // cout<<"Make sure to watch out for the snake on the field!"<<endl;
    // cout<<"The snake is S, it eats the rabbits"<<endl;
    // cout<<"and is trying to bite you!"<<endl;
    // cout<<"If you are bitten you will lose the newest 5 vegetables!\n"<<endl;
    cout<<"Good Luck!\n"<<endl;
}

void GameEngine::printField()
{
    cout<<"\33[34m#\33[0m";
    for(int j = 0; j<width; j++)
    {
        cout<<"\33[34m###\33[0m";
    }
    cout<<"\33[34m#\33[0m"<<endl;
    for(int i = 0; i<height; i++)
    {
        cout<<"\33[34m#\33[0m";
        for(int j = 0; j<width; j++)
        {
            if(field[i][j]!=nullptr)
            {
                cout<<" "<<field[i][j]->getsymbol()<<" ";
            }
            else
            {
                cout<<"   ";
            }
        }
        cout<<"\33[34m#\33[0m"<<endl;
    }
    cout<<"\33[34m#\33[0m";
    for(int j = 0; j<width; j++)
    {
        cout<<"\33[34m###\33[0m";
    }
    cout<<"\33[34m#\33[0m"<<endl;
}

int GameEngine::getScore()
{
    return score;
}

void GameEngine::timerTick()
{
    if(timer%5 == 0)
    {
        if(int(rabbits_on_field.size())<MAXNUMBEROFRABBITS)
        {
            cout<<"Oh no! Here comes another rabbit!"<<endl;
        }
        spawnRabbits();
    }
    timer++;    
}

void GameEngine::moveRabbits()
{
    long long unsigned int bunny_count = rabbits_on_field.size();
    int direction; //there are 8 directions to travel in. The 12 o'clock direction is 0 is incremented in the clockwise direction.
    int bunnyheight, bunnywidth, new_h, new_w;
    bool bunny_move = false;//to check if the bunny can move in an empty map within bounds.
    for(long long unsigned int i = 0; i<bunny_count; i++)
    {
        bunny_move = false;
        direction = rand()%8;
        bunnyheight = rabbits_on_field[i]->getheightpos();
        bunnywidth = rabbits_on_field[i]->getwidthpos();
        switch(direction)
        {
            case 0:
                if(bunnyheight != 0)
                {
                    bunny_move = true;
                    new_h = bunnyheight-1;
                    new_w = bunnywidth;
                }
                break;
            case 1:
                if(bunnyheight != 0 && bunnywidth != width-1)
                {
                    bunny_move = true;
                    new_h = bunnyheight-1;
                    new_w = bunnywidth+1;                   
                }
                break;
            case 2:
                if(bunnywidth != width-1)
                {
                    bunny_move = true; 
                    new_h = bunnyheight;
                    new_w = bunnywidth+1;                 
                }
                break;
            case 3:
                if(bunnyheight != height-1 && bunnywidth != width-1)
                {
                    bunny_move = true;
                    new_h = bunnyheight+1;
                    new_w = bunnywidth+1;
                }
                break;
            case 4:
                if(bunnyheight != height-1)
                {
                    bunny_move = true;
                    new_h = bunnyheight+1;
                    new_w = bunnywidth;
                }
                break;
            case 5:
                if(bunnyheight != height-1 && bunnywidth != 0)
                {
                    bunny_move = true;
                    new_h = bunnyheight+1;
                    new_w = bunnywidth-1;
                }
                break;
            case 6:
                if(bunnywidth != 0)
                {
                    bunny_move = true;
                    new_h = bunnyheight;
                    new_w = bunnywidth-1;
                }
                break;
            case 7:
                if(bunnyheight != 0 && bunnywidth != 0)
                {
                    bunny_move = true;
                    new_h = bunnyheight-1;
                    new_w = bunnywidth-1;
                }
                break;
        }
        if(bunny_move)
        {
            if(field[new_h][new_w] == nullptr)
            {
                field[new_h][new_w] = new Rabbit(new_h,new_w);
                rabbits_on_field[i]->setheightpos(new_h);
                rabbits_on_field[i]->setwidthpos(new_w);
                delete field[bunnyheight][bunnywidth];
                field[bunnyheight][bunnywidth] = nullptr;
            }
            else if((dynamic_cast<Veggie*>(field[new_h][new_w])))
            {
                cout << "rabbit gouing to eat";
                delete field[new_h][new_w];
                field[new_h][new_w] = nullptr;
                field[new_h][new_w] = new Rabbit(new_h,new_w);
                rabbits_on_field[i]->setheightpos(new_h);
                rabbits_on_field[i]->setwidthpos(new_w);
                delete field[bunnyheight][bunnywidth];
                field[bunnyheight][bunnywidth] = nullptr;
            }
            else
            {
                bunny_move = false;
            }
        }
    }
}

// @param The input direction is +1 or -1 to move up or down respectively
void GameEngine::moveCptVertical(int input_direction)
{
    int h = player->getheightpos(), w = player->getwidthpos();
    Veggie* check_template_veggie;
    Rabbit* check_template_rabbit;
    Snake* check_template_snake;
    if((h + input_direction) >= 0 && (h + input_direction) < height)
    {
        player->setheightpos(h+input_direction);
        if(field[h+input_direction][w] == nullptr)
        {   
            field[h+input_direction][w] = new Captain(h+input_direction, w);
            field[h+input_direction][w] = player;
            field[h][w] = nullptr;
        }
        else if((check_template_veggie = dynamic_cast<Veggie*>(field[h+input_direction][w])))
        {
            cout<<"Yummy! A delicious "<<check_template_veggie->getveg_type()<<endl;   
            player->addveggie(check_template_veggie);
            score = score + check_template_veggie->getpt_val();
            delete field[h+input_direction][w];
            field[h+input_direction][w] = new Captain(h+input_direction, w);
            field[h+input_direction][w] = player;
            field[h][w] = nullptr;
        }
        else if((check_template_rabbit = dynamic_cast<Rabbit*>(field[h+input_direction][w])))
        {   
            for(long long unsigned int i  = 0; i<rabbits_on_field.size(); i++)
            {
                if(rabbits_on_field[i]->getheightpos() == check_template_rabbit->getheightpos() && rabbits_on_field[i]->getwidthpos() == check_template_rabbit->getwidthpos())
                {
                    delete rabbits_on_field[i];
                    rabbits_on_field.erase(rabbits_on_field.begin() + i);
                }
            }
            cout<<"Finally got one of those pesky bunnies!"<<endl;
            score = score + RABBITPOINTS;
            delete field[h+input_direction][w];
            field[h+input_direction][w] = new Captain(h+input_direction, w);
            field[h+input_direction][w] = player;
            field[h][w] = nullptr;
        }
    }
    else
    {
        cout<<"You can't move that way!"<<endl;
    }
}


void GameEngine::moveCptHorizontal(int input_direction)
{
    int h = player->getheightpos(), w = player->getwidthpos();
    Veggie* check_template_veggie;
    Rabbit* check_template_rabbit;
    Snake* check_template_snake;
    if((w + input_direction) >= 0 && (w + input_direction) < width)
    {
        player->setwidthpos(w+input_direction);
        if(field[h][w+input_direction] == nullptr)
        {   
            field[h][w+input_direction] = new Captain(h, w+input_direction);
            field[h][w+input_direction] = player;
            field[h][w] = nullptr;
        }
        else if((check_template_veggie = dynamic_cast<Veggie*>(field[h][w+input_direction])))
        {   
            cout<<"Yummy! A delicious "<<check_template_veggie->getveg_type()<<endl; 
            player->addveggie(check_template_veggie);
            score = score + check_template_veggie->getpt_val();
            delete field[h][w+input_direction];
            field[h][w+input_direction] = new Captain(h, w+input_direction);
            field[h][w+input_direction] = player;
            field[h][w] = nullptr;
        }
        else if((check_template_rabbit = dynamic_cast<Rabbit*>(field[h][w+input_direction])))
        {   
            for(long long unsigned int i  = 0; i<rabbits_on_field.size(); i++)
            {
                if(rabbits_on_field[i]->getheightpos() == check_template_rabbit->getheightpos() && rabbits_on_field[i]->getwidthpos() == check_template_rabbit->getwidthpos())
                {
                    delete rabbits_on_field[i];
                    rabbits_on_field.erase(rabbits_on_field.begin() + i);
                }
            }
            cout<<"Finally got one of those pesky bunnies!"<<endl;
            score = score + RABBITPOINTS;
            delete field[h][w+input_direction];
            field[h][w+input_direction] = new Captain(h, w+input_direction);
            field[h][w+input_direction] = player;
            field[h][w] = nullptr;
        }
        else if((check_template_snake = dynamic_cast<Snake*>(field[h][w+input_direction])))
        {   
            delete field[h][w+input_direction];
            field[h][w+input_direction] = new Captain(h, w+input_direction);
            field[h][w+input_direction] = player;
            field[h][w] = nullptr;
            //The snake will be called next and thus will bite the player
        }
    }
    else
    {
        cout<<"You can't move that way!"<<endl;
    }
}

void GameEngine::moveCaptain()
{
    string input;
    int direction;
    cout<<"Would you like to move up(W), down(S), left(A), or right(D): ";
    cin>>input;
    if(input.compare("W") == 0 || input.compare("w") == 0)
    {
        direction = -1;
        moveCptVertical(direction);
    }
    else if(input.compare("S") == 0 || input.compare("s") == 0)
    {
        direction = 1;
        moveCptVertical(direction);
    }
    else if(input.compare("A") == 0 || input.compare("a") == 0)
    {
        direction = -1;
        moveCptHorizontal(direction);
    }
    else if(input.compare("D") == 0 || input.compare("d") == 0)
    {
        direction = 1;
        moveCptHorizontal(direction);
    }
    else
    {
        cout<<input<<" is not a valid option!"<<endl;
    }
}

void GameEngine::gameOver()
{
    cout<<"GAME OVER!"<<endl;
    cout<<"You managed to harvest the following vegetables:"<<endl;
    player->printallveggies();
    cout<<"Your score was: "<<score<<endl;
}