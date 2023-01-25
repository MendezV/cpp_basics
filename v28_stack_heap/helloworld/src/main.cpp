/*
memory

two types stack heap
what they are, how and where are they use
why we care

program starts it gets divided in areas in memory
more than these two, but stack and heap, but these are the main ones

what the OS does when we launch program:
load instructions to memory and allocate a certain space in RAM for the instructions to run
- each program/process on our computer has its own stack/heap
- each thread will create its own stack when it gets created, whereas the heap is shared amongst all threads

both stack and heap are areas in ram,

stack has predefined size ~2Mb
heap has a predefined value but it can change and grow as the application grows

the physical location is the same - RAM
even though stack might be more 'hot' in communicating with cache in the CPU

both work very differently but they do the same
we ask for a certain ammount of memory, C++ gives us that

the difference is in how this memory is allocated


*/

struct Vector3
{
    float x,y,z;

    Vector3()
        : x(10), y(11), z(12) 
        {

        }
        

};

#include <iostream>
#include <string>

int main()
{
    int value =5; // allocating in the stack
    
    int* hvalue =new int;  //allocation in heap
    *hvalue =5;

    //for arrays
    int array[5]; //stack
    for(int i=1;i<5;i++)
        array[i]=i;
    int* harray = new int[5]; //heap
    for(int i=1;i<5;i++)
        harray[i]=i;

    //for classes 
    Vector3 vector; //stack //calls the constructor implicitly
    Vector3* hvector= new Vector3();// heap //calls the constructor explicitly


    // looking at memory, it will be allocated close
    // as the stack pointer moves and allocates by the number of 
    // bytes that we allocated (in debug stack also adds safeguards between stack allocations to prevent overflow into nearby mem)

    // most stack implementations grow backwards

    // heap is in random locations

    // make unique or make shared with smart pointers would also allocate in heap


    //heap memory has to be manually destroyed
    delete hvalue;
    delete[] harray;
    delete hvector;

    // with stack the memory gets freed after we exit a scope
    //could just be empty scope
    {
        int arrayscope[5]; //stack
         for(int i=1;i<5;i++)
            arrayscope[i]=i;
    }

    //stack gets a free delete
    // relevant videos are the lifetime and new keyword

    // how the heap works
    // this calls malloc, this in turn call the OS to interface with hardware
    // when the progarm begins we keep a freelist, which tracks what memory is free

    // when we ask for dynamic memory malloc keeps track of what is free, what is in use by what
    // this is implementation dependent and is a very heavy function in general, 
    // when we call new, it searches in freelist and records that a portion of memory is now taken

    // If we ask for too much memory, malloc has to ask again the os and this is very slow
    // allocation in the heap is a whole thing - in the stack it is a single cpu instruction
    
    // also closeness in memory is an argument for stack once 
    // we have to allocate several thousand times
    // maybe a few cache misses wont affect performance greatly


    //REASONS FOR HEAP 
    // object is too large 
    // lifetime has to survive scope

    //STACK whenever possible

    // TO HAMMER THE POINT
    // the allocation is the heavy part for heap
    // usually access is not a severe issue






}