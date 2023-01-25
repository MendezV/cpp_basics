#include <iostream>
#include <string>
#define LOG(x) std::cout << x << std::endl

/*
Templates in c++

generics ?
different, infinitely more powerful

more like a macro, whereas generics is limited by the type system

allows to define a template that will be compiled by usage
get the compiler to write for me based on rules that I give it

write function and I use a template, I'm giving a blueprint
and the parameters that I specify in that function will be determined
at compile time by the usage of the function

*/

void Print(int value){
    LOG(value);
}
void Print(std::string value){
    LOG(value);
}

template<typename T> //could have also said template<class T> , type and class are interchangeable here
void printfy(T value)
{
    LOG(value);
}


//templated array class in the stack
template<typename T,int N>
class Array 
{
    private: 
        T m_array[N]; //this has to be known at compile time
    public:
        int get_size() const 
            {
            return N;
            }
};


//goal of software engineering is to reduce code
//duplication, can we improve the above?


int main()
{
    //create a function that is the same
    // but takes different types
    Print(5);
    Print("hol"); //would return error but could still work
                  // if I overload the function with a different type

    //instead of overloading, we can define a templated function
    printfy("\nhol");
    printfy(5);
    printfy(5.01f);

    //how does this work?
    // the templated block is not
    // actual source until it gets compiled
    // at which point the use will determine
    // what code gets written
    

    //more transparent use that explicitly shows the template parameters
    printfy<std::string>("\nhol");
    printfy<int>(5);
    printfy<float>(5.01f);

    Array<int,5> array;
    LOG("\ntesting get size \n");
    LOG(array.get_size());

    //templates can get any argument!


    // metaprograming
    // programing what the compiler will generate

    //where do we want to use templates and where not

    // some game studios ban templates

    // there is a point where the template
    // gets so complicated that it is impossible to
    // tell what is being compiled
    // templates are a bit fragile and hard to understand if overused

    //logging systems, material system for rendering?
}