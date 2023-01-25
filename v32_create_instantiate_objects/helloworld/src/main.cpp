#include <iostream>
#include <string>
/*
how to create objects

when we write a class
we usually instantiate the class

the options are heap or stack

we need the memory to keep track of the 
attributes that distinguish the particular
object

stack objects have automatic lifetime
things die within the scope

heap is different, big misterious place,
where once we allocate, its going to sit there
until we decide to free

*/

using String =std::string;


class Entity
{
    private:
    String m_name;
    public:
    Entity()
    : m_name("Unknown")
    {

    }
    Entity(const String& name)
    : m_name(name)
    {
        
    }
    const String& GetName() const {return m_name;} 
};
int main()
{
    //creating on the stack
    Entity entity; // calling the default constructor
                    // null ref exception? no, this does call constructor
    std::cout << entity.GetName() << std:: endl;


    Entity entity2= Entity("Mendo"); // calling the default constructor
                    // null ref exception? no, this does call constructor
    std::cout << entity2.GetName() << std:: endl;
    

    // pretty much all the time we want to do this
    // most managed version 

    // if we want to extend lifetime we would use heap


    //example
    Entity* e;
    {
        Entity entity2("Mendo"); //brief way of calling the constructor
        e=&entity; //bp
        
        std::cout << entity2.GetName() << std:: endl;
    

    }
    //keeping track of what the reference points to 
    // after the stack pops, we see that 
    // the object dissapears

    // allocating in the heap
    // 

    Entity* e2;
    {

        Entity* entity3 = new Entity("Mendo"); //brief way of calling the constructor
        e2= entity3; //bp
        std::cout << (*entity3).GetName() << std:: endl;
        std::cout << entity3->GetName() << std:: endl;
    
    }
    delete  e2;
    // Java, everything is on the heap

}