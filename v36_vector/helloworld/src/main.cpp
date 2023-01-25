#include <iostream>
#include "Log.h"
#define LOG(x) std::cout<<x<<std::endl

#include <vector>
/*
dynamic arrays

standard vector class
standard template library:
library filled with containters, container types


we can template it into any data type

underlying data type of the containter is up to
the programer to decide

class vector in the std namespace

vector is like arraylist or dynamic array

-set that does not enforce uniqueness
 this can actually resize

-standard template library is not super optimized

how does this work? 
every time the array grows it reallocates in a different 
place in memory, copies the data and adds a new position
and then erases the previous data

all of these allocations happen in the heap
*/
struct Vertex
{
     float x,y,z;

    //default constructor for declaring arrays
    Vertex()
     {

     }


     Vertex(float x, float y, float z)
     : x(x), y(y),z(z)
     {

     }

    //copy constructor
     Vertex(const Vertex& vertex)
     : x(vertex.x), y(vertex.y),z(vertex.z)
     {
        LOG("copied!");
     }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y  << ", " << vertex.z; 
    return stream;
}

void function(const std::vector<Vertex>& vertices)
{
    //asdfads
}

int main(){
    //static array, ignoring std
    Vertex v[5]; //in the stack
    LOG("will print garbage without def constructor \n");
    for( int i=0; i<5; i++)
        LOG(v[i]);
    Vertex* v2 = new Vertex[5];
    delete[] v2;

    LOG("\n");
    // both are tied to the size

    // if we want to keep adding vertices
    // entering data from user

    // an option would be to put an absurd limit on the size
    // of the static array, but this is wasteful

    std::vector<Vertex> v3; //not a bunch of pointers, inline objects
    // should we use 
    // std::vector<Vertex*> v4; //?
    // this would lead to memory fragmentation, bad for iterating
    // on the other hand when resizing, it is easier to copy pointers

    // moving instead of copying helps but still carries overhead

    //because this is a templated class, we can use primitive types
    //std::vector<int> v3;
    // in java we would need to use the integer class
    // std::vector<Integer> v3;

    //try to use inline vector as a first recourse 

    //adding stuff
    v3.push_back({1,2,3}); //using three ints as class members?
    v3.push_back({4,5,6});

    //in a c style we dont know size here we have a method for this

    //size is a long unsigned int, for comparisson declare i as  such
    for( long unsigned int i=0; i<v3.size(); i++)
        LOG(v3[i]); //the [] operator is overloaded from the getter of this class, not possible in Java

    LOG("\n");
    //range based for works with vectors
    for (Vertex v : v3) //this copies the vertex in the scope of the for (ineficient)
        LOG(v);

    LOG("\n");

    for (Vertex& v : v3) //this does not copy in the scope
        LOG(v);

    LOG("\n");

    // v3.clear() ; // back to zero size

    // to erase , the argument is an
    // iterator object, we would proceed as
    v3.erase(v3.begin() +1); // deletes the second element, begin() returns an iterator , + is overloaded to sum ints 

    for (Vertex& v : v3) //this does not copy in the scope
        LOG(v);
    

    // when we pass vectors to functions
    // pass them by reference
    // and if we are not modifying them, pass by const reference
    // so that we do not copy arrays around


    //the above is not so bad, but we want to sqeeze all the performance
    LOG("\n");

    /*
    Optimization

    knowing environment, how things work and what do I need to do exactly
    what should happen

    vast subject, we focus only on the usage of vector

    our strategy is to avoid copying when storing a vector
    of objects (instead of a vector of pointers to objects)

    when do copies happend and how do they happen
    */


    std::vector<Vertex> v4;

    v4.push_back(Vertex(1,2,3)); 
    LOG("\n");
    v4.push_back(Vertex(4,5,6));

    //how many if any copies are in the above code?
    //three initially
     LOG("\n");

    v4.push_back(Vertex(7,8,9));

    //now its six copies

    /*
    first we create vector in stack of main and COPY to vector class
    this happens everytime we call the constructor

    we then copy whatever was previously in the vector to the new
    location, these are the additional copies
    */
    LOG("\n");
    LOG("start optimizations:reserve");
    std::vector<Vertex> v5;
    v5.reserve(3);
    v5.push_back(Vertex(1,2,3)); 
    v5.push_back(Vertex(4,5,6));
    v5.push_back(Vertex(7,8,9));
    LOG("\n");
    //three copies instead of 6
    LOG("\n");
    LOG("optimizations: reserve and emplace");
    std::vector<Vertex> v6;
    v6.reserve(3);
    v6.emplace_back(1,2,3);  //pass the parameter list for the constructor
    v6.emplace_back(4,5,6);
    v6.emplace_back(7,8,9);
    LOG("\n");


    return 0;

}
