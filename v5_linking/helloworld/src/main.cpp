#include <iostream>
#include "Logger.h"

// compilation generates separate translation units (object files), it is then the job of the linker
// to stitch together these units (find where each symbol and funtions is and then link together)

// even with a single file, the linker has to find the entry point (main)

// error codes that start with C occurred during compilation 
// error codes that start with LK occurred during linking (in visual studio)
 


// static : promise to the linker that this function is only used in this translation unit (so if it is not used here, its dead code)
// otherwise, we could have a linking error if the functions inside of THIS function are not defined
// this is because THIS function could theoretically be called from elsewhere in the project
static int Multiply( int a , int b){
    Log( "multiplying");
    return a*b ;
}

//another type of linking error would happen when we have duplicate symbols
//ie we have a function that is defined twice, once in different files
//  (if it was twice in the same file it would be a compile error)

//duplicate symbols can sneak up while using header files

int main(){

    std::cout << Multiply(5,8)<< std::endl;
    std::cin.get();
    
}
