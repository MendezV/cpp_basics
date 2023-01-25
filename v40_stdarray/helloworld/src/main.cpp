#include <iostream>
#include <array>
#define LOG(x) std::cout << x << std::endl
/*
std array

standard template library 
static arrays -- arrays that do not grow

*/

// for printing the standard array 
template<typename T,int sizearr>
void print( const std::array< T, sizearr >& array)
{
    for(unsigned int i =0 ; i<array.size() ;i++)
    {
        LOG(array[i]);
    }
}

int main()
{   
    const int sizestack=6;
    std::array<int, sizestack> data={0,0,0,0,0,0};
    // LOG(data[0]);
    print<int,sizestack>(data);
    LOG("\n");
    data.fill(10); //to fill the array with a single alue
    print<int,sizestack>(data);

    int dataold[sizestack]={1,1,1,1,1,1};
    LOG("\n");
    LOG(dataold[7]);
    LOG("\n");

    //testing the bounds check for debug
    // LOG(data[5]); //cpp14?

  

    // only change is the type in the declaration
    // otherwise the behavior is the same


    // on the surface how does it work and what are the
    // advantages

    // if they don't offer benefits, it doesnt make sense to use them

      // stl algorithms are available since we have iterators
      // sorting can be done on this, etc

    // one of the main advantages is that we do not have to 
    // maintain the size of the array separatedly

    // performance is not affected since this is defined in the stack
    // vector is defined in the heap instead!!

    //debug mode has bounds checking!

    // the size is not stored! it is a template argument


}