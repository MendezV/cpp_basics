#include <iostream>
#include <string>
#define wait std::cin.get() // pastes std::cin.get() everytime it encounters wait
#define LOG(x) std::cout<<x<<std::endl
#define MIN(a,b) (((a)<(b)) ? a : b)

//If we are not testing the logging code does not get pasted
// #ifdef _TEST
// #define LOG(x) std::cout<<x<<std::endl
// #else
// #define LOG(x) 
// #endif
//some pieces of the code wont even be tried to be compiled

//slightly improved version
#if TEST==1 //assign values to the build types
#define LOGs(x) std::cout<<x<<std::endl
#elif defined(RELEASE)
#define LOG(x) 
#endif



#define OPEN_CURLY { //ridiculous example
/*
Macros

broad term: using the preprocesses to macrofy different 
operrations

use preprocessor to automate certain tasks

text editing stage - find and replace of sorts

control what code gets fed to the compiler

macro that replaces text with something else

this can be complex 

templates happen later, this is just text manipulation in the end

overusing macros can be confusing for readers
*/
int main()
OPEN_CURLY
    
    wait; // defining a macro
          // changes the way in which the text is passed
         // to the compiler but is equivalent to just writting the line explicitly

    
    //example is stupid and shouldnt be done in general

    // not how the preprocessor is used

    // if #define wait std::cin.get()  was in another file
    // would encounter trable

     LOG("hello"); //arguments in macros

     //more complicated logging systems can make use of this

     //strip logging info in release mode
     #ifdef TEST
     LOG("testing");
     #endif

    // eliminating section of the code
    #if 0
    LOG("hello"); //arguments in macros

     //more complicated logging systems can make use of this

     //strip logging info in release mode
     #ifdef TEST
     LOG("testing");
    #endif

     //macros are more useful for debugging 
     //backslash for new line in macros

    #endif
}