#include <iostream>
#define LOG(x) std::cout<<x<<std::endl

/*
Operators in C++

whats an operator
a symbol that stands for a function 

examples
dereference *, reference &, bitshift left <<, arrow ->
sum +, +=

others
new, delete

weirds 
, coma operators
() parenthesis operator

list of ops here
https://www.programiz.com/cpp-programming/operators

overloading: giving a new meaning
define or change the behavior of an operator

kind of a good thing but allows for weird errors, be careful

minimal use of operator, and evident (people shouldnt need to go to the definition)


operators are just functions
just because we can does not mean we should

common overloads:
    to string
    comparisson between two objects

*/

struct vec2{
    float X,Y;
    vec2(float x , float y)
    : X(x), Y(y)
    {

    }
    vec2 Add(const vec2& other) const //returns a NEW vec2 pass the second vector
    // to avoid copying we pass by const reference
    // const at the end since we are not modifying the attributes
    {
        return vec2(X+other.X,Y+other.Y); //calling the constructor
    }


    void print()
    {
     LOG(X);
     LOG(Y);   
    }

    vec2 Multiply(const vec2& other) const //elementwise mult
    {
        return vec2(X*other.X,Y*other.Y); //calling the constructor

    }

    vec2 operator+(const vec2& other) const //can define this first and then the add function or vice versa
    {
        return Add(other); //calling the constructor
    }

    vec2 Add2(const vec2& other) const
    {
        return *this + other; //also valid, this is a pointer, we are dereferencing first
        // another option return operator+(other); calls like a function
    }

    vec2 operator*(const vec2& other) const //can define this first and then the add function or vice versa
    {
        return Multiply(other); //calling the constructor
    }

    vec2 scalarMultiply(float x) const //elementwise mult
    {
        return vec2(X*x,Y*x); //calling the constructor

    }
    vec2 operator*(float x) const //float mult
    {
        return vec2(X*x,Y*x); //calling the constructor

    }
    //overloading equals
    bool operator==(const vec2& other) const
    {
        return (X==other.Y) && (Y == other.Y);
    }

    bool operator!=(const vec2& other) const
    {
        return !((*this)==other);
    }
    
};


//overloading << in cout
std::ostream& operator<<(std::ostream& stream, const vec2& other)
{
    stream << other.X << ",  " << other.Y;
    return stream;
}

int main(){
    vec2 position1(4.0f,4.0f);
    vec2 position2(0.5f,1.5f);
    vec2 fac(0.5f,0.5f);
    vec2 result =position1.Add(position2);
    result.print();
    vec2 result2 =result.Multiply(fac);
    result2.print();

    //this gets a bit hard to read // in java this is the only choice
    // have to also impose op precedence

    //now we can do 
    vec2 result3 =position1 +position2*fac;
    result3.print();

    LOG(result3);
    LOG(result3*2.0f); //can do multiple overloads

    
    return 0;

}

//classes are there for ease, only syntactic sugar

