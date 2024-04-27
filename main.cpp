    #include"GameEngine.h"

    int main()
    {
        srand((150));
        GameEngine game;
        game.initialzeGame();
        game.intro();
        int remaining_vegetables = game.remainingVeggies();
        //cout<<remaining_vegetables<<endl;
        while(remaining_vegetables != 0)
        {
            cout<<remaining_vegetables<<" veggies remaining. ";
            cout<<"Current score: "<<game.getScore()<<endl;
            game.printField();
            game.moveRabbits();
            game.moveCaptain();
            remaining_vegetables = game.remainingVeggies();
            game.timerTick();
            cout<<endl;
        }
        game.printField();
        game.gameOver();
        return 0;
    }