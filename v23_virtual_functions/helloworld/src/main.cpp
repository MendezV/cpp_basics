#include <iostream>
#include <string>
/*
virtual functions are important in object oriented programming

say we have to classes A and B, B is derived from A

we can overwritte a function from A in B
*/
class Entity
{
    public:
        virtual std::string GetName() {return "Entity";}
};

class Player : public Entity
{
    private: 
        std::string m_name;
    public:

        //constructor
        Player(const std::string& name)
        : m_name(name){} //constructor list .. later

        std::string GetName() override {return m_name;} //override is not necessary but is good practice form c++11
};


//trouble starts if I do the following without doing virtual
void PrintName(Entity * entity)
{
    std::cout << entity->GetName()<< std::endl;

}
// I can call this with player,
// but instead of looking for the GetName in player
// it will look for the GetName in Entity, since that is 
// the type of the argument


/*
solution is to use virtual functions
dynamic dispatch implemented by a vtable

a table of all the functions in the base class
so that we can map them to the correct overwritten function

to mark the functions that will appear in the vtable
we have to mark with virtual the funciton in the base class

two sources of overhead,

1) extra memory to keep vtable 
member pointer in the member class

2) cost of going through the table 

keep in mind for performance, but is usually not that bad
*/

int main()
{
    Entity* e= new Entity();
    std::cout << e->GetName()<< std::endl; //arrow operator allows to call methods from pointers to objects
                                            // shortcut to first dereferencing the ponter and then calling the method

    Player* p= new Player("Mendo");
    std::cout << p->GetName()<< std::endl;

    PrintName(e);
    PrintName(p); // may not be what we want

}