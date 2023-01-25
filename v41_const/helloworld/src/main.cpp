#include <iostream>
#include <string>
#define LOG(x) std::cout << x << std::endl

/*
const 

like a fake keyword
more like a promise to the compiler and a
help to developers 

the promise can be broken with the mutable keyword

*/

class Entity 
{
    private:
        int m_x, m_y;
        int* z, *w; //to declare a bunc of pointers in the same line

        mutable int var; // if we really need to change this inside const methods
    public:

        Entity()
        : m_x(0),m_y(0), z(&m_x), w(&m_y)
        {}
        int getx() const // the method does not modify the attributes
        {
            return m_x;
        }

    // for a setter this does not make sense, we want to modify
    // attributes
        void setx(int x){
            m_x=x;
        }
        const int* const getz() const  // returns a pointer that cant be changed to
                                        // a readonly part of memory that cant be changed
                                        // and this method does not change the attributes of the class
        {
            return z;
        }

        //const actually enforces behavior of external functions

};

void printEntity(const Entity& e) // need to pass by const reference to avoid copying
{
    LOG(e.getx()); // we can call this only if there is const in the method
                    // there wouldnt be guarantee that e is not modified otherwise
}

int main()
{
    const int a=5;
    // a=3; //error
    const int Max_age=90; //simple example of why use this

    // pointer uses 
    int* b = new int;
    *b=2;
    b= (int*)&Max_age; // need to cast const int * to int *
    LOG(*b);

    const int * c = new int; // pointer to a const int
                             // this is in a readonly
                             // part of memory, cannot
                             // dereference and modify

                             // address can be changed contents not
    // *c=a; throws error
    int * const d = new int; // the pointer is const
                             // cannot modify the address d

                             // contents can be changed address not
    // d=b; throws error

    // const int * c is equivalent to  int const * c
    // distinction is whether const is before or after *

    // delete b; the pointer leaves on the heap but points to the stack
                // looks bad, should not be doing this
    //now in classes and methods

    Entity e;
    printEntity(e);

}