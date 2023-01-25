/*

smart pointers are wrappers around regular
pointers, they will call new but they will 
make sure that the memory is deleted in the end


first kind is unique pointer
they are in the heap but are scoped 
they cant be copied because when they get deleted 
the copy would point to a location in memory that has been freed



*/
#include <iostream>
#include <string>
#include <memory> 

using std::unique_ptr;
// using std::make_unique;

using std::shared_ptr;
using std::make_shared;

// using std::weak_ptr;
// using std::make_weak;

using std::cout;
using std::endl;

class Entity
{
    public:
        int x;
        Entity()
        {

            cout<<"Created entity"<<endl;
        }
        ~Entity()
        {
            cout<<"Destroyed entity"<<endl;
        }
        void Print(){}
};


int main()
{
    {
        unique_ptr<Entity> entity_instance( new Entity() );  //only option before c++14
        // std::unique_ptr<Entity> entity_instance = std::make_unique<Entity>(); //slightly safer if the constructor throws exception
        // unique_ptr<Entity> e = entity_instance; // thorws error, copy constructor does not exist for unique pointer
        entity_instance->Print();
        //very low overhead
    }
    // shared pointers do not have the limitation of not being copyed 
    // work with reference counting, additional counter of how many pointers 
    // are referencing the block of memory, when the count is zero the memory gets freed
    {
        shared_ptr<Entity> entity_instance = make_shared<Entity>(); //slightly safer if the constructor throws exception
        shared_ptr<Entity> entity_instance2 = entity_instance; //slightly safer if the constructor throws exception

        entity_instance->Print();
    }

    //example of how shared works
    {
        shared_ptr<Entity> e0;
        {
            shared_ptr<Entity> e1 = make_shared<Entity>();
            e0=e1;
        }

    } //memory allocated in e1 only gets destroyed here when the copy made in e0 dies
    

    // unique is the first option, no overhead
    // shared is second option a little overhead


    //for arrays
    {
        unique_ptr<Entity[]> entity_instance( new Entity[5] );  //only option before c++14
        // std::unique_ptr<Entity> entity_instance = std::make_unique<Entity>(); //slightly safer if the constructor throws exception
        // unique_ptr<Entity> e = entity_instance; // thorws error, copy constructor does not exist for unique pointer
        (entity_instance[0]).Print();
        //very low overhead
    }

    /*
    what does it mean to be safe?
    reduce crashes, memory leaks or access violations
    move towards smart pointers and away from raw

    problem: allocating in the heap
             automate to reduce human error
             make life easier and programs more robust
             
    if things go right we will have a pointer to the begining of that memroy
    until the memory is deleted. 

    what happens if we forget to release memory? could be harmless leak or
    or the program could crash because we ran out of memory
    
    who owns that memory? passing the memory around from class to class and
    function to function, we dont know who finishes last, who is in charge of deleting?

    transfer ownership is too hard to maintain

    automation comes from the single instructions of deletion

    raw pointers are good for small applications for readability

    other considerations are for multithreaded applications and multiprocessing
    constraints from smart pointers could be too severe (shared pointers are not thread safe)
     
    regardless of safety, one needs to know about raw pointers to understand smart ones
    since the later are just a wrapper
    
    */
}
