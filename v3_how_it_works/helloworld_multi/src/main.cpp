#include <iostream>

// need iostream in each file for that uses std for the moment. Since the include pastes the code that has the actual cout, cin functions

// need a declaration for the function that is no longer defined here
// a promise that this exists -compiler will believe that it exists somewhere
// it is then the job of the linker to find that function

// declaration vs definition of a function -> the function exists vs this is what the function is 
void Log( const char* message);

int main(){

    Log("Hello World!");
    std::cin.get();
    
}
//compilation of each individual file works well now 

//common error in linker would be unresolved external symbol, there is a declaration without a definition 