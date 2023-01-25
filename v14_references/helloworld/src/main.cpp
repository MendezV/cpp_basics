#include <iostream>
#define LOG(x) std::cout<<x<< std::endl;
#include <cstring>

// references are extensions of pointers
// pretty much the same thing
// semantically they are different
// syntax sugar on top of pointers
// reference an existing variable - they have to reference an already existing memory



void increment(int value){
    //same as 
    //int Value=value;
    // Value++;
    //nothing would happen to the input
    value++;
}

//for things to actually increment for the input
// we pass the pointer to the memory and modify that location
// in memory

void increment2(int* value){

    (*value)++; //dereferencing the pointer first
                // order of operations would prioritize
                // increasing pointer before dereferencing
}

//the most straightforward way is to pass the reference
void increment3(int& value){

    value++; 
}

int main(){

    int a =5;
    int* b= &a; //address of a
    int& ref =a; //reference,
                 //created an alias
                 // not a new variable
    ref =2;
    LOG(a);
    LOG(b);

    increment(a);
    LOG(a); //nothing happens a new variable is
            //created inside the function

    
    increment2(&a);
    LOG(a);

    increment3(a);
    LOG(a);

    // references cannot be changed after declaration;
    /*
    if I had done 
    int b=8;
    ref=b;

    i end up with 
    a=8,b=8;
    references are like an alias

    if I wanted the functionality above, we need pointers

    int* ref=&a;
    ref =&b;

    */

    return 0;

}


// things that can be done with references 
// can be done by pointers
// but pointers are more powerful

// references can look cleaner, use them when possible