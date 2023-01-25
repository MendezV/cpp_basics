#include <iostream>
#include "Log.h"
#define LOG(x) std::cout<<x<<std::endl
#include <string>
#include <cstring>

/*
copy data

we want to avoid if it is not needed,
this is an expensive operation

getting it to work and stopping when unneeded
*/

struct Vector2
{
    float x,y;

    void print(){
        LOG(x);
        LOG(y);
    }
};

// copy-able string class
// raw for illustration// possibly faster than
// modern class
class String
{
    private: 
    char* m_buffer;
    unsigned int m_size;
    public:
    String(const char* string)
    {
        m_size=strlen(string);
        m_buffer=new char[m_size+1]; // should have +1 for null termination character
        //copy the value to the buffer
        // for (int i =0; i<m_size;i++)
        //     m_buffer[i]=string[i];
        // cleaner way
        memcpy(m_buffer, string, m_size+1); //destination, source, size (missing null termination here)
        //strcpy includes null termination caracter
        m_buffer[m_size]=0; // adding null termination manualy

    }
    String(const String& other)
        : m_size(other.m_size) //it is fine to shallow copy primitive types
    {
        //default is a memcpy
        //memcpy(this, &other, sizeof(String));
        //if we dont want to copy the pointer but
        // the memory at the pointer we modify this

        //if we want to disallow copy
        // String(const String& other)=delete;
        // this is what unique pointer does

        m_buffer = new char[m_size+1];
        memcpy(m_buffer, other.m_buffer, m_size +1);
        // assuming the other string has the null termination char
        // since this comes from the constructor
        LOG("Copy!");
    }
    ~String()
    {
        //we had a memory leak, we used new in the constructor
        //have to immedaitely delete in here
        delete[] m_buffer;

    }
    const char* get_buffer() const
    {
        return m_buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_buffer[index]; //no bound check
    }
    //another way
    friend std::ostream& operator<<(std::ostream& stream, const String& str);
};

//overloading flush stream in cout
std::ostream& operator<<(std::ostream& stream, const String& str)
{
    // stream <<  str.get_buffer();
    stream <<  str.m_buffer;
    return stream;
}

void FunctionPrint(String string)
{
    LOG(string);
}
void FunctionPrint_ref(const String& string)
{
    LOG(string);
}

int main(){

    int a =2;
    int b=a;
    LOG("copy but can be modified\n");
    LOG(b);
    LOG(a);
    //these are two memory addresses that are different
    // but that contain the same data
    b=4;
    LOG("\n");
    LOG(b);
    LOG(a);
    LOG("\n");
    // we can modify b without affecting a
    
    //for classes and structs
    LOG("copy for objects\n");
    Vector2 v={1,2};
    Vector2 w=v;
    v.print();
    w.print();
    w.x=3;
    LOG("\n");
    v.print();
    w.print();

    //v will remain unaltered

    //if we heap allocate with new instead
    Vector2* vh =new Vector2();
    Vector2* wh=vh;
    //now I'm copying the pointer instead of the object 
    wh->x=2; // this affects both vh and wh 
            //since I'm modifying the data, not the address

    //almost always the equal sign between 
    // two variables generates a copy

    // the exeption is for references, which instead
    // directly modify the data that is at 
    // the location that the reference points to
    LOG(" ref does not copy\n");
    LOG(b);
    LOG(a);
    int& ref = b;
    ref=a;
    LOG("\n");
    LOG(b);
    LOG(a);
    LOG("\n");

    LOG("string copy \n");
    String str("cosas");
    LOG(str);

    //now we copy
    String str2=str; 
    LOG(str2);

  

    // this crashes in the end 
    // when we call the destructor we freed
    // m_buffer for the first object,
    // we then call the destructor for the second
    // object and the program crashes

    // we need to copy the objects in a different way
    // instead of blindly copying the attrubutes of the class "shallow copy"
    // (which is what the default copy constructor does)
    // we have to make a "Deep Copy" not just copy the addresses
    // for attribute pointers, but copy the underlying data in a new address
    
    LOG("\n overloaded index operator [] \n");
    str2[1]='a';
    LOG(str);
    LOG(str2);

    // this would modify both str and str2 in the shallow
    // copy since the underlying pointer is the same

    // if we want the two objects to contain the same data but
    // be independent in the way in which int copying works
    // we have to do a "deep copy"
    // copied object has its own unique pointers with the same data

    //one way is clone method which is trash, we instead use a copy constructor
    // constructor gets called upon assingment 
    // copy constructor gets called if the object that is being assigned is a class instance


    //now we defined an external function
    LOG(" \n Calling print ");
    FunctionPrint(str);
    LOG("the function copied the string ");
    FunctionPrint_ref(str);
    LOG("passing as (const) reference fixes this behavior");

    //ALWAYS pass object arguments as reference or const reference

}
