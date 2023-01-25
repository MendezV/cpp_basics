#include <iostream>
#include "Logger.h"

void Log( const char* message){
    std::cout << message << std::endl;
}


//ways in which we could have a linking error


// void Log( const char* message, int level){
//     std::cout << message << std::endl;
// }
// void Logr( const char* message){
//     std::cout << message << std::endl;
// }

// int Log( const char* message){
//     std::cout << message << std::endl;
//     return 0;
// }

// the signature (type name and arglist) has to match exactly for the linker to find the function

