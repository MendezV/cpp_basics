#include <iostream>

/*
Arrays

basics are pointer (integers of an address)

array is a collection of variables in a row
multiple variables in a single one
*/

class Entity{
    int example[5]; //allocated this ammount of memory contiguously where entity is
    int* another = new int[5];  // this will only store the direction of where the array is
                                // but not the contiguous block of memory
                                // this results in memory fragmentation (performance hit)
    public:
    Entity()
    {
        for(int i=0; i<5;i++){ //<=4 gives performance hit due to double comparisson
        another[i]=2;
        example[i]=2;
    }

    }
};

int main()
{
    int example[5]; //allocated this ammount of memory
    example[0]=0; //arrays start with 0 here
    example[4]=4; //writting t
    std::cout << example[0] << std::endl;
    std::cout << example << std::endl; //prints the memory address

    // int a =example[0];

    // example[5] memory access violation in release mode will not give error
    
    for(int i=0; i<5;i++){ //<=4 gives performance hit due to double comparisson
        example[i]=2;
    }
    //data is stored contiguously

    //array is really an integer pointer
    int* ptr =example;
    example[2]=4; //writting to an offset of 8 (=2 x (sizeof(int))) bytes from the pointer address /bp
    *(ptr+2)=5; // these two are equivalent expressions, pointer arithmatic moves depending on underlying type  /bp
    *(int*)((char*) ptr+8 )=6; //equivalent expression with pointer arithmatic changing to 1 byte char /bp
    std::cin.get(); //bp


    //array creation
    //in the heap
    int* another = new int[5]; //lifetime is different, does not get destroyed when the scope ends
    delete[] another;

    for(int i=0; i<5;i++){ //<=4 gives performance hit due to double comparisson
        another[i]=2;
    }

    // the reason to allocate dynamically is if I want to return the array from a function
    // if it was in stack the memory would just be released

    //memory indirection example
    Entity e;

    // untrusty to determine size, compiler dependent
    int a[5];
    int count =sizeof(a)/sizeof(int); //5
    int* aptr= new int[5];
    int count =sizeof(aptr)/sizeof(int); //the first size of is the size of an int since aptr is a pointer

    static const int size = 5;
    int example[size]; //arrays in the stack have sizes that have to be determined at compile time!!
    //DYNAMIC ALLOCATION    
    //size is determined at runtime
}
