#include <iostream>

/*
Constructor

a special type of method that runs every time we 
instantiate an object

even without a constructor there is a default
empty constructor that runs when I instantiate

in java constructor sets ints to 0
here they are set to whatever leftover crap was in memory

constructors can have parameters

VERY IMPORTANT TO INITIALIZE MEMORY


Destructor
runs when an object gets destroyed

uninitializes any memory used by the object
if we use the heap with the 'new' keyword, this gets called when we destroy
if we use stack, when we exit the scope of the function, memory is released and objects are destroyed

*/



class Entity{
   public:
    float X,Y;
    
    //no return type and the same name as the class
    Entity()
    {
        X=0.0f;
        Y=0.0f;
        std::cout<< "Constructed Entity" <<std::endl;

    }

    //can have many constructors with the same name but different
    //parameters. This works the same as with function overload

    Entity(float x, float y)
    {
        X=x;
        Y=y;

    }

    // manually allocated memory has to be freed
    // to avoid memory leaks
    // allocated memory during the lifetime of the object
    // has to be freed in the destructor

    // free opposes new

    // possible to do e.~Entity() but not common

    ~Entity()
    {

        std::cout<< "Destructed Entity" <<std::endl;

    }

    // If I want a class without instances, only static methods for instance
    // then I make private the constructor

    //constructors dont run If I dont instantiate

    void Print()
    {
        std::cout<< X<<" , "<< Y <<std::endl;
    } 

};

class Log
{
    // private:
    //     Log(){}
    
    public:
        Log()=delete; //can no longer create instances 
        static void Write(){

        }
};

//copy and move constructors also
//setup whenever we create a new object instance
// we do this to exit a scope and destroy the objects in stack
void function(){ 
    Entity e; //bp
    e.Print(); //bp
}

int main(){
    // Entity e;
    // e.Print();

    // Entity e2(1.0f,10.0f);
    // e2.Print();

    Log::Write();
    // Log log; //throws error

    function();
    
    return 0; //bp

}





