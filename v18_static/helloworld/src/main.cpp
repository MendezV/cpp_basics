#include <iostream>
#define Log(x) std::cout<<x<<std::endl 

// static keyword
// two versions, inside a class/struct or outside

// outside is for the linker to know
// that the funciton will only be used in
// the translation unit where it is defined

// inside a class it means that the memory
// of the attribute defined will be shared among all
// instances

// static methods

// int s_Variable =10; //global variable
                       // all global variables need different names

extern int s_Variable; //external linkage: looks 
                        //in other translation units for this
                        //if the variable is static then it becomes
                        //private and this will not work
void function(){

}
// for now we will focus on static outside class
int main(){
    Log(s_Variable);
    return 0;

}

//if static is pasted in a header file
// the functions and variables will be private
// to each individual file where the header was
// included

// we want to use static as much as possible
// so that variables are not declared globally accross
// files leading to nasty errors
