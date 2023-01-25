#include <iostream>
#include "Log.h"

/*
Inheritance

hierarchy of classes

allows to have a base class with basic functionality
and branch from that class and create subclasses

helps avoid code duplication .. can change functionality slightly or introduce new functionality

*/

class Entity
{
    public: 
        float X,Y; //position
        void Move(float xa, float ya)
        {
            X+=xa;
            Y+=ya;
        }
};

//without inheritance

class Player
{
    public: 
        const char* name;
        float X,Y; //position
        void Move(float xa, float ya)
        {
            X+=xa;
            Y+=ya;
        }
};

//with  inheritance
/*
now player_v2 has both types

anything non-private in Entity is accessible in player
*/

class Player_v2 : public Entity // inherit entity
{
    public: 
    const char* name;
    void PrintName()
    {
        std::cout<< name << std::endl;
    }
    
};

//without inheriting only new functions
class Player_v3
{
    public: 
        const char* name; //8 bytes in mac
    void PrintName()
    {
        std::cout<< name << std::endl;
    }
        
};

/*
Polymorphism

idea of having multiple types for a single type
we can use a player wherever we can use an entity

player is always as superset

players can be set as arguments of functions that take entity

we can overwritte methods
*/

int main(){
    Player_v2 player;
    player.name="yo";
    player.PrintName();
    player.Move(5,5);
    player.X=4;

    std::cout << sizeof(Entity) << std::endl;
    std::cout << sizeof(Player_v3) << std::endl;
    std::cout << sizeof(Player_v2) << std::endl;
    //result of the last should be the sum of the two former

    // if we overwritte functions we need to keep track, occupies
    // more memory, with vtable
    return 0;

}

