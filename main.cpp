/* Author: Archith J, Ikshwak Jinesh
Date: 5-2-2024
Description: Program containing the main function which starts the game and stops when all the veggies have dissapeared and prints out the field.
*/

#include"GameEngine.h"

    int main()
    {
        //The time is randomized to make the game interesting.
        srand(unsigned(time(0)));
        GameEngine game;
        //The game field and vegetables, the player character and a snake is created during initialization. The timer is set to 0.
        game.initialzeGame();
        //wwalkthrough on how to play the game.
        game.intro();
        //Remaining Vegetables is the number of vegetables on the field.
        int remaining_vegetables = game.remainingVeggies();
        //The game runs till there are no more vegetables on the field.
        while(remaining_vegetables != 0)
        {
            cout<<remaining_vegetables<<" veggies remaining. ";
            cout<<"Current score: "<<game.getScore()<<endl;
            game.printField();
            game.moveRabbits();
            game.moveCaptain();
            //The snake is moved after the captain.
            game.moveSnake();
            remaining_vegetables = game.remainingVeggies();
            //The timer is incremented by 1.
            game.timerTick();
            cout<<endl;
        }
        game.printField();
        //The player is informed about the vegetables in the basket when the game is over.
        game.gameOver();
        return 0;
    }
