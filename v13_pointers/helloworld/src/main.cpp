#include <iostream>
#define LOG(x) std::cout<<x<< std::endl;
#include <cstring>
// wall pointers -not smart pointers
// memory - most important thing in computing, variables, loading data, etc
// pointers are helpful in managing memory 
// pointer is an integer that stores a memory address

// memory is like a big line - single street with a row of houses
// every house has an address - houses are bytes
// addresses are pointers

// pointers are just integers, types are nothing
// 

int main(){

    //simplest pointer is a void pointer

    void* ptr0 =0;
    LOG(ptr0)
    
    // the only meaning of the type is that the
    // data is presumed to be of the type specified

    //zero is an invalid memory address
    // zero means NULL #define NULL 0
    // acceptable state though
    // nullptr in c++11

    int var =8;
    void* ptr = &var; // & gets the address of the variable
    LOG(ptr)

    // same behavior
    int* ptr2 = &var; // & gets the address of the variable
    LOG(ptr2)

    // types help read and write, but otherwise are meaningless

    // I have access to the location of the data, how do I modify it
    // DEREFERNCING
    LOG(var)
    *ptr2=10; //here is where types comes in
              // we tell this to the compiler but we could be wrong
              // errors like that would lead to a segmentation fault 

    LOG(var)

    // people say that pointers point to a block of memory
    // but this is inaccurate, we dont know the size

    // the pointers above where to data in the stack portion of the memory
    

    // what about the heap?
    char* buffer = new char[8]; // allocated 8 bytes of memory and returns
                                //pointer to the start of that block

    memset(buffer, 'a', 8); //fills starting from the pointer, 
                            //using the second arg, for as many times as the third arg
    LOG(buffer)
    


    // pointers are also variables and are also in memory
    // we have pointers to pointers and pointers to pointers

    char** ptr_buff = &buffer; //bp
    LOG(ptr_buff) //bp
    delete[] buffer;

    return 0;

}
