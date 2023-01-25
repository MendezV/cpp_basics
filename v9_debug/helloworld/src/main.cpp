#include <iostream>
#include "Log.h"

// important to understand the ins and outs of the program

// two big parts of debugging 
    // breakpoints
    // reading memory

// they are done in conjunction

// point is to remove bugs in code - computer is always right (99%)
// figure out programer mistakes

// breakpoints halt the execution of the program and let you look 
// at the current state of memory (variables, which function call comes next, etc)

// continue just continues the execution
// step into goes into the function I'm currently at
// step out goes out of the current function I'm in

int main(){

    // local shows local variables
    // in watch I can set what variables to track in the execution
    // have to compile first with debug conf
    // can track the actual memory address and see if it has been allocated
    // by hovering I can see what the hex number translates to different types UTF+8 int32, etc

    // each two hex characters is a byte 
    int a = 8;
    char cc;
    a++; //increases a by 1  //bp
    std::cout<<a<<std::endl;
    a++; //increases a by 1  //bp
    std::cout<<a<<std::endl;

    const char* message="hello";

    for(int i=0; i<5;i++){
        cc=message[i];
        std::cout<<cc<<std::endl; //bp

    }
    
    Log("Hello world!"); 
    return 0;

}

