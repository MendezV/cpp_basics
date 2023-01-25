#include <iostream>
#include "Log.h"
#define LOG(x) std::cout<<x<<std::endl

//classes
// OOP
// style to adop when writting code
// c++ doesn't enforce this styly while c# does
// c does not support it , no classes or objects

// almost always a good idea

// group data and functionality together

// game: representation of the player
//       attributes, speed at which the player moves
//                    position in the map, 3d model

// functions will have to specify all attributes
// many argumens, huge mess
class Player{ // unique name// new type

    public:
        int x,y;
        int speed;

    //cleaner code than having the function to be external
    void Move_in( int  xa, int ya){ //pass player by reference since we would be modifying attributes
    x += xa * speed;
    y += ya * speed;
    }
};

//external function that moves the player
void Move(Player& player, int  xa, int ya){ //pass player by reference since we would be modifying attributes
    player.x += xa *player.speed;
    player.y += ya *player.speed;
}
//but classes can also contain functionality
// we can put this function as part of the class, make it a method

int main(){
    // the collection of variables that are made of class types are called objects
    // new object variable is an instance

    Player player1; //instantiated a player object
    // player1.x =5; // not possible unless we make this attribute visible
                    // by default, we have attributes as private in C++ classes

    //setting
    player1.x =5;
    player1.y =5;
    player1.speed =1;
    LOG(player1.x);
    LOG(player1.y);

    Move(player1,1,-1);
    LOG(player1.x);
    LOG(player1.y);

    player1.Move_in(1,-1);
    LOG(player1.x);
    LOG(player1.y);
    
    return 0;

}

//classes are there for ease, only syntactic sugar

