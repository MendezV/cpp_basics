#include <iostream>
#include <string>
/*
interfaces or pure virtual functions
are ones that are not defined in the base class

base class cannot be instantiated but can then serve as template for derived classes

derived classes have to provide definitions for the interfaces
*/

//interface
class Printable
{
    public:
        virtual std::string GetClassName() =0; //pure virtual declaration
};

//only nead 
class Entity : public Printable
{
    public:
        virtual std::string GetName() {return "Entity";}
        std::string GetClassName() override {return "Entity";}
};

class Player : public Entity //, Printable
{
    private: 
        std::string m_name;
    public:

        //constructor
        Player(const std::string& name)
        : m_name(name){} //constructor list .. later

        std::string GetName() override {return m_name;} //override is not necessary but is good practice form c++11
        std::string GetClassName() override {return "Player";}
};


//trouble starts if I do the following without doing virtual
void Print(Printable * obj)
{
    std::cout << obj->GetClassName()<< std::endl;

}

// classes need to implement this or else we will not be able
// to instantiate
// primary use for pure virtual functions is to 
// enforce an implementation of a method for derived classes

int main()
{
    Entity* e= new Entity();
    std::cout << e->GetName()<< std::endl; //arrow operator allows to call methods from pointers to objects
                                            // shortcut to first dereferencing the ponter and then calling the method

    Player* p= new Player("Mendo");
    std::cout << p->GetName()<< std::endl;

    Print(e);
    Print(p);

}