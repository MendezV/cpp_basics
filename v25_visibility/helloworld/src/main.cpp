#include <iostream>
/*
visibility in OOP

who can see attributes and methods
no effect in performance

only there to write better code

three modifiers
private 
protected
public


*/

//default visibility for class is private
//structs are public instead
class Entity
{
    private:  //only this class and Friends can access, both attributes and methods
        int X,Y;
        void Print(){}
    protected:
        int X2,Y2; //this class and derived classes can access
        void Print2(){}
    public:
    Entity(){
        X=0;
    }
    int X3,Y3; //this class and derived classes can access
    void Print3(){}

};
class Player : public Entity
{
    Player(){
        X2=0;
        Print2();
    }
    
};

int main()
{
    Entity e;
    e.Print3();
    e.X3=2;
    

}

/*
why make things private or protected

its a bad idea for maintainability
private tells everyone that this shouldn't be accessed externally

is suggestive of what the proper usage of the class is
If I see a function that does something
probably the author intended that I use some other function that is public
and achieves the result better

one example is UI - access to position of a button
                    maybe we can change this but that does not update
                    the position of the button, I need to do more operators (refresh screen)
                    and there is actually a public method that does everything.
*/