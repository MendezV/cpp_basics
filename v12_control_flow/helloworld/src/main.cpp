#include <iostream>
#include "Log.h"


// control flow statements work with loops
// give control on execution of loops

//continue : inside a loop, go to next iteration
//break : loops or switch, gets out of the loop
//return : gets out of the function 



int main(){

        //continue
       for (int i=0;i<5;i++){
        if (i%2 ==0)
            continue;
        Log("Hello world!");
        std::cout << i<< std::endl;
        // continue; //wouldn't modify the behavior here
        }

        Log("\n");
        for (int i=0;i<5;i++){
        if (i>2)
            continue;
        Log("Hello world!");
        std::cout << i<< std::endl;
        }

        //break
        Log("\n");
        for (int i=0;i<5;i++){
        if (i>2)
            break;
        Log("Hello world!");
        std::cout << i<< std::endl;
        // seemingly behaves the same as continue above 
        }

        Log("\n");
        for (int i=0;i<5;i++){
        if (i%2 ==1) //breakpoint
            break;
        Log("Hello world!");
        std::cout << i<< std::endl;
        // prints only the first one and exits 
        }

    // return can be anywhere in the code
    return 0;
}

