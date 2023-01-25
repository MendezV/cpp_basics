/*
lifetime for stack based variables

understanding how things live on the stack

how to leverage the behavior

data structure where we stack things on top
first in last out

everytime we enter a scope {} we push a stackframe

book analogy , stack memory is like a stack of books
when we enter  a scope we put an additional book,
writting variables is like writing on the book. 
once we exit the scope we throw the book away,
information is gone.

*/
#include <iostream>
#include <string>


class Entity
{
    public:
        int x;
        Entity()
        {

            std::cout<<"Created entity"<<std::endl;
        }
        ~Entity()
        {
            std::cout<<"Destroyed entity"<<std::endl;
        }
};


//will fail, memory will be freed after we exit the scope
int* CreateArrayFails()
{
    int array[50];
    return array;
}

//will succeed since the array was created in the heap
int* CreateArraySucceeds()
{
    int* array = new int[50];
    return array;
}

// another option is to simply modify an array that was
// allocated further up the stack
void CreatedArray(int* array)
{
    //fill array,
}

//mistake: function that returns a pointer to a stack based variable

/*
ways to leverage this behavior
smart pointer
timer class
mutex lock of threads so that different threads can't access a function within a scope
*/

//example smart pointer, a pointer allocated in heap that gets destroyed automatically
// when it goes out of scope

class ScopedPtr
{
 private:
    Entity* m_Ptr;
 public:
    ScopedPtr(Entity* ptr)
    :m_Ptr(ptr)
    {

    }
    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};

int main()
{
    //scopes are anything with {}
    // fors ifs functions whiles

    // but also just empty scopes
    {
        Entity e; //bp
    }

    // but also just empty scopes
    {
        Entity* e = new Entity(); // does not get destroyed //bp
                                  // OS does free the memory used by process after execution
    }

    //scoped pointer
    {
        //implicit conversion allows this to work
        ScopedPtr ptr = new Entity(); //essentially a wrapper
    }
}
