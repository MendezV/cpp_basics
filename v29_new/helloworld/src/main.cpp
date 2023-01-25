/*
new keyword

there is a lot that goes in this way of allocating

this allocates in the heap, determines size of allocation in bytes from type
and returns a pointer to the begining of the allocated segment

new needs to find where we have contiguous memory
freelist keeps track of where free memory is
*/

#include <iostream>
#include <string>
using String = std::string;

class Entity
{
    private:
        String m_Name;
    public:
        Entity () :m_Name("Unknown"){} // constructor
        Entity(const String& name) : m_Name(name){}

        // const in the begining means that the function returns
        // a string that cannot be changed 
        // const before scope means that the function will not change
        // the attributes of the class
        const String& GetName() const { return m_Name ;}


};

int main()
{
    int a =2;
    int* b= new int;
    *b=2;

    // for an array
    int* barr = new int[50]; // 200 bytes 50x4 
    Entity* e  =new Entity(); //also calls the constructor
    // for arras
    Entity * e_arr = new Entity[50];
    // this is like 50 entities in the stack
    // but it is continuous in the heap

    // new is an operator (which can be overloaded)
    // it is just a function that returns a void pointer

    //this is dependent on the compiler, but usually
    //new calls malloc
    // Entity* e2 =(Entity*) malloc(sizeof(Entity));
    //similar to the above but without calling the constructor
    //each instance of new, has to be followed by a delete (calls free)

    // no way of telling the free list that the memory was released otherwise
    delete e;
    delete[] e_arr; // square brackets. this is a different operator

}