#include <iostream>
#include <cstring>
#include "Log.h"

// two parts to if statements, evaluation and branching depending on the condition
// implies jumping around in source code (machine instructions)
// these jumps carry overhead, we want to minimize them

int main(){

    int x=5;
    bool condition_res= x==5;
    // double equal, equality operator
    // essentially a function that returns a bool
    // overloaded operator

    //grabbing bytes of memory and comparing 
    //can toggle assemby by doing lldb show disassembly
    
    if (condition_res){ //if (condition_res==true)
        Log("Hello world!");
    }

    // the condition is a boolean, which is nothing but asking
    // whether the condition is 0 or not
    // null pointer is 0

    const char* ptr =nullptr;  //to check whether a pointer is null
    if (ptr)
        Log("ptr is not null");
    else
        Log("ptr is null");


    const char* ptr2 ="Hello";  

    if (strcmp( ptr2, "Hellows") == 0)
        Log(ptr2);
    else if (strcmp( ptr2, "Hello") == 0) // to compare strings
        Log("the pointer was indeed Hello");
    else
        Log("ptr is null");

    /*
    else if is an abbreviation of 

    else{
        if (xxx){

        }
    }
    */

   // mathematical vs logical programming
   // usually math is faster
   // logic (a bit more boring?)
    

    return 0;

}

