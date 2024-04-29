#ifndef GameEngine_h
#define GameEngine_h
    #include"Captain.h"
    #include"Rabbit.h"
    #include"Veggie.h"
    #include"Snake.h"
    // This class controls all the elements of the game. 
    class GameEngine
    {
        private:
            //FieldInhabitant *** is the feild in which the entities will be populated.
            FieldInhabintant *** field;

            //The maximum number of vegetables that the field should have is stored in this variable.
            const int NUMBEROFVEGGIES = 30;
            //The maximum number of rabbits that may appear on the field at once.
            const int MAXNUMBEROFRABBITS = 5;
            //The point value of catching a rabbit.
            const int RABBITPOINTS = 5;
            //These variables store the size od the field, the score of the player and the cycles for which the game has been running for.
            int width, height, score, timer;
            //The player is member of the Captain class and stores a list of the vegetables the player has collected.
            Captain* player;
            //This is the list of rabbits on the field and the list can have a maximum size of MAXNUMBEROFRABBITS.
            vector<Rabbit*> rabbits_on_field;
            //This is the list of all the possible types of vegetables that may be used tp populate the field with.
            vector<Veggie*> possible_veggie;
            //function to populate the field with vegetables.
            void initVeggies();
            //function to initialize the position of the player at the start of the game.
            void initCaptain();
            //function to spawn one rabbit onto the field.
            void spawnRabbits();
            //function to initialize the snake.
            void initSnake();
            //function to move the captain vertically based on the user input.
            void moveCptVertical(int input_direction);
            //function to move the captain horizontally based on the user input.
            void moveCptHorizontal(int input_direction);
        public:
            //This function initialized the game prior to the start.
            void initialzeGame();
            //This funtion introduces the game to the user.
            void intro();
            //This funtion prints the field and all its members onto the termial.
            void printField();
            //This function randomly moves all the rabbits on the field.
            void moveRabbits();
            //This function gets user input to move the captain and calls the required function.
            void moveCaptain();
            //This function increments the cycle count.
            void timerTick();
            //This function informs the user of the completeion of the game and deletes the field.
            void gameOver();
            //This function returns the player score.
            int getScore();
            //This function counts the number of vegetables left on the field.
            int remainingVeggies();
    };
#endif