#pragma once
void Log( const char* message);


// #include <iostream>

// this is undesirable since each include will copy the def of the function


// void Log( const char* message){
//     std::cout << message << std::endl;
// }

// solutions include replacing 

// static void Log( const char* message){
//     std::cout << message << std::endl;
// }
// each tranlation unit will have its own Log function (yuk)

// or
// inline void Log( const char* message){
//     std::cout << message << std::endl;
// }
// literally copies and pastes the line