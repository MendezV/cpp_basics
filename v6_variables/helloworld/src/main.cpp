#include <iostream>

// programs manipulate data
// variables allow us to retrieve data for use in the program
// ex: player in a game, storing position and update when the player moves

//variables can be stored in one of two places, stack or heap

//variables can be one of several data types
// cpp has defaults with purposes intended, but it is not necessary 
// to stick to those puproses 

//!!!!the only true difference between primitive data types is their size 

int main(){
    int variable = 8; // not necessary to give a value immediately
                      // int is 4 bytes (depends on compiler)
                      // signed int from -2bn -> 2bn 
                      // otherwise will require more data to store  

    std::cout << variable << std::endl;

    // why the range? 
    // 1 byte is 8 bits, 32 bits in total, one bit for the sign 2^31=2147483648 values including 0

    int variable_none = 2200000000;
    std::cout << variable_none << std::endl;

    // to use the additional bit
    unsigned int variable_l = 2200000000;
    std::cout << variable_l << std::endl;

    //other types
    //char  1 byte -> can be numbers or letters both are interchangeable but cout has conventions
    //short 2 byte
    //long  4 byte (depending on compiler)
    //long long 8 byte

    float varf=5.5f; // 4 bytes (have to append f)
    double var=5.5; // 8 bytes

    bool t=false; // 0 is false and everything else is true
    std::cout << varf << var << t << std::endl;
    // bools are size 1 byte, only would need 1 bit, but memory can only be
    // retrieved in bytes

    //we can check sizes with sizeof - since this is compiler dependent
    std::cout << sizeof(bool) << std::endl;
    std::cout << sizeof(float) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(long long) << std::endl;

    // all primitive types can be modified to be
    // references or pointers -> later video


}
