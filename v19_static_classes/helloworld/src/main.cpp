#include <iostream>
#define Log(x) std::cout<<x<<std::endl 



// now we do static inside classes/structs
// OOP languages
// static makes it so that there is only that 
// one variable for all instances 
// same for static method (cannot refer to a particular instance)

struct Entity{
    int x,y;
    static int z;
    void print()
    {
        std::cout<<x<<" , "<<y<<std::endl ;
    }
    //static method is the same as if I wrote the method outside
    //the class 

    //usual methods have access to the attributes of the instance
    // sort of like hidden arguments
    static void Print()
    {
        // std::cout<<x<<" , "<<y<<std::endl ; //a nonstatic member reference must be relative to a specific objec
        std::cout<<z<<std::endl;
    }
};
/*
new operator scope ::
1) access a global variable when there is a local variable with the same name
2) define function outside class
3) access a class static variables <<<< here
4) multiple inheritance resolving symbols
5) for namespace
6) for a class inside another class
*/
int Entity::z;

int main(){
    Entity e;
    e.x=2;
    e.y=3;


    Entity e1 ={5,8}; // with an initializer
    e.print();
    e1.print();

    Log("\n");
    e.z=2;
    Log(e.z);
    e1.z=4;
    Log(e.z);
    Log("\n");

    Entity::z=4; // this is like we have a namespace named Entity (they don't 'belong' to the class)
    Entity::Print(); //static methods cannot access non-static variables

    return 0;

}

