#include <iostream>
// everything that starts with a hash is a preprocessor statement
// first thing a compiler does is to perform preprocessor statements

//include copies and pastes the code in the header file declared
// iostream has the declaration of cout

//main is the entry point for the application

//execution will proceed in order unless there are control flow statements or function calls


//main is a special function, if we dont return anything it returns 0
int main(){
    std::cout << "Hello world "<< std::endl;
    //here the notation obscures the meaning
    //  the 'bitshift operator' was overloaded
    // operators are basically functions
    // the meaning is closer to 
    // std::cout.printf("Hello world ").printf( std::endl);
    // << is like pushing into

}

//compilation

// for compilation configuration in build type, debug/release and architechture
// build type is the set of rules for the building of a project - platform specifies processor, etc
// these can be modified in CMAKE to tune the level of optimization and the different build types


//header files do not get compiled, only included - only cpp files are compiled 


//after each cpp file is compiled - object files .obj are generated
// these are stitched together using the linker
// settings with Cmake 


//errors
// usually looking at output looks better - the error console looks for every line that contains error

// single file compilation with cmake active file