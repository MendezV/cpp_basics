#include <iostream>

// functions: blocks of code designed to perform a specific task 

// later with classes these will be methods

// functions occur outside classes, objective is to prevent code duplication
// aids maintainability
// funtions, input and output (although output is not necessary)

// return type, name
int multiply(int a , int b){
    return a*b;
}

// void to make it not return anything
void mult_and_log(int a , int b){
    int result;
    result = multiply(a,b);
    std::cout<< result<<std::endl;
}

int main(){
    int result;
    result = multiply(3,3);
    std::cout<< result<<std::endl;

    mult_and_log(3,2);
    mult_and_log(8,5);
    mult_and_log(3,3);

    // do not overdo 
    // harder to maintain, messy code
    // can make the code slower
    // everytime we call function 
    // *
    // everytime we call we need to generate entire stack frame
    // push parameters, return address into stack
    // go to a different part of the binary for execution and then come back
    // jumping around memory takes time

    // * if the compiler does not inline the function
    return 0; //optional

}

// basic: functions avoid code duplication

// breakup: declarations and definitions
// declarations in header files