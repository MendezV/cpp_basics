#include <iostream>
#include "Log.h"
// header files why do we use them?
// a lot of languages don't have these
// two types of files -tranlation units and headers

// more than just declarations of functions

// for now, the basics is that this serves as a common place to store
// declarations of functions

// traditionally, we include header files with the #include preprocessor directive


int main(){
    InitLog();
    Log("Hello world!");
    return 0;

}

// what is the deal with some of the includes being <>
// and other being ""

// <> if the file is in the include path folders
// "" relative path to the current file

// c standard library have the extension fully included #include <stdlib.h>
// c++ standard library do not! but they are still files