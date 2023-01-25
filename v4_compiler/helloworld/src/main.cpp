#include <iostream>

// what does the compiler do? 

// big picture
// c++ code is nothing but text
// transform text into application, executable binary

// two operations need to happen - compilation and linking

// the compiler then transform the text files into an intermediate 
// file (object file)
// which is then passed on to the linker for the linker to do its thing

// several things are done to create object files
//      preprocessor statements are evaluated
//      (abstract syntax tree) tokenizing and passing 'english' code to something the compiler can understand
//      in the end, code has to be transform into either static data or instruction sets

//in java class name has to be linked to file name 
//folder hierarchy has to be tied to package
//java expects certain files to exist
//cpp is nothing like this

// in cpp - no such thing as a file (they are meaningless), a file is a way to feed the 
// compiler with source code - there are default conventions .cpp .c or .h but these can be overwritten

// because several cpp files can be included into a big one
// the unit that we work with is a 'translation unit' for the compiler
// each translation unit becomes an object file

// preprocessing
// common ones define, if, ifdef, include, others like pragma which tell the compiler what to do


// .i files show the files after preprocessing
// with cmake one can do make make src/math.i for the preprocessed code

// include: copy and paste file (illustration by solving a missing bracket with include)
// define: (#define INTEGER int) , this searches and replaces exactly the first word for the second
// if (#if condition ... #endif) excludes or includes based on condition

//illustration with math.cpp

// .s files show the assembly code output
// with cmake one can do make make src/math.s for the assembly code

// debug mode for cmake generated assembly code of roughly 300 lines
// with release optimizations where turned on and the code is now 40 lines

// optimizations
//  constant folding - every operation that can be worked at compile time , is
//  compiler can remove entire code sections if they are deemed useless

//illustration with math.cpp and useless function within

void Log( const char* message);

int main(){

    Log("Hello World!");
    std::cin.get();
    
}
