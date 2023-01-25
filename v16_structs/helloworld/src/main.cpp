#include <iostream>
#include "Log.h"
#define LOG(x) std::cout<<x<<std::endl

//structs

// when should we be using this over class

// no diference, only default visibility
// if didn't declare public I would be able to use Move_in outside the class

//default is private
class Player{ 

    public:
        int x,y;
        int speed;

    //cleaner code than having the function to be external
    void Move_in( int  xa, int ya){ //pass player by reference since we would be modifying attributes
    x += xa * speed;
    y += ya * speed;
    }
};

// default is public
// backwards compatibility with c
struct Player2{ 


    int x,y;
    int speed;

    //cleaner code than having the function to be external
    void Move_in( int  xa, int ya){ //pass player by reference since we would be modifying attributes
    x += xa * speed;
    y += ya * speed;
    }
};

// usage is the difference
// cherno: structs for plain old data, buching values
                                        //vector class
//not a lot of functionality (comparing to player, which renders updates states, iteracts)
struct vec2{
    float x,y;

    //only manipulating these objects together
    void Add(const vec2& other){
        x=other.x +x;
        y=other.y +y;
    }
};

//design difference is that Player is way more massive in terms of code

// not inheritance with structs
// additional complexities warrant classes

int main(){

    Player player1; //instantiated a player object
    // player1.x =5; // not possible unless we make this attribute visible
                    // by default, we have attributes as private in C++ classes

    //setting
    player1.x =5;
    player1.y =5;
    player1.speed =1;
    LOG(player1.x);
    LOG(player1.y);


    player1.Move_in(1,-1);
    LOG(player1.x);
    LOG(player1.y);
    
    vec2 vector1, vector2;
    vector1.x=0.0;
    vector1.y=1.0;
    vector2.x=1.0;
    vector2.y=0.0;

    LOG('\n');
    vector1.Add(vector2);
    LOG(vector1.x);
    LOG(vector1.y);

    vector1.Add(vector1);
    LOG(vector1.x);
    LOG(vector1.y);

    return 0;

}

//classes are there for ease, only syntactic sugar

