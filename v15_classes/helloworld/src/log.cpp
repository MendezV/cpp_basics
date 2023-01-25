#include "Log.h"
// #include "Log.h"
#include <iostream>
// //declaration
// void Log(const char* message); //function signature
// // would have compilation error if the function didn't have a declaration


void Log(const char* message){
    std::cout<< message<<std::endl;

}

void InitLog(){

    Log("initializing log");

}