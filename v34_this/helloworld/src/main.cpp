#include <iostream>
#include "Log.h"
#define LOG(x) std::cout<<x<<std::endl

//this keyword
/*
only accessible through a member function 
(method of a class, has to be non-static)
pointer to the current object instance 


needs to be first instantiated
pointer to that object

dont use
delete this; !!!!!!

*/


class Entity{ 

    //declaration has to be here
    void PrintEntity(Entity* e);
    void PrintEntity_v2(const Entity& e);


    public:
        int x,y;
    Entity(int x, int y)
    // :x(x), y(y) valid but what if I want to do it in the 
    {
        // Entity * const e =this ; //the type of this, I'm assinging the value of this to e
        // const to the left of e means that the pointer leads to 
        // a pointer that is constant, I cannot reasign
        // this =nullptr. (const modifies the pointer operator)

        // e->x=x; //valid way of settingx
        // (*this).x=x; //also valid
        this->x=x;
        this->y=y;
        PrintEntity(this);
        PrintEntity_v2(*this);

        //from the point of view of references
        // Entity& e =*this;

    }

    //inside a const function, this is a bit different
    //hover pointer over 'this to see the difference'
    int GetX() const 
    {
        //const Entity * e =this ;
        //here const is in the other side, the reference itself 
        // cannot be changed, pointer to a const Entity
        // (const modifies the type)
        return this->x;

        //from the point of view of references
        // const Entity& e = *this;
    }

    
    //another case for using a cons Entity this is if we have an external function

    
};


void PrintEntity(Entity* e)
    {
        //cool printity
    }
void PrintEntity_v2(const Entity& e)
    {
        //printing const ref arg
    }


int main(){

  
    return 0;

}

//classes are there for ease, only syntactic sugar

