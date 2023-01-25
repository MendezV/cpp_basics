#include <iostream>
#include "Log.h"

//loops are for repeating instructions, performing operations multiple times

// for a game, keep a game running (game loop) while the game is running
// keep updating the game




int main(){

    // for loops
    //iterator initial cond; condition for termination; update instruction
    for (int i=0;i<5;i++)
        Log("Hello world!");


    //order initial cond body upd cond body upd cond .. upd until cond is not fulfilled
    Log("\n");

    //equivalent way of writting this
    //first and last spots can be whatever line of code and middle just has to be a bool
    int j=0;
    bool condition=true;
    for (;condition;){
         Log("Hello world!");
         j++;
         if (!(j<5))
            condition=false;
    }
    

    Log("\n");
    //the order of evaliations is the same
    // even function calls can happen in the first and last segments of the for

    //repeating -going through arrays

    //equivalent to the for loop above, we have
    int k=0;
    while(k<5){
        Log("Hello world!");
        k++;
    }

    // why use one over the other?
    // usually when we need something like a counter we use for
    // the loops are equivalent , more a matter of convention

    // condition that doesn't change usually warrants while

    Log("\n");
    Log("k is equal to");
    std::cout<<k<<std::endl;
    //also we have do while, it will always enter at least once (not like while)
    do{
        Log("enter once Hello world!");
    }while(k<5);

    return 0;
}

