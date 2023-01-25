#include <iostream>
// #include <string> // to be able to print strings
#define LOG(x) std::cout << x<< std::endl

#include <stdlib.h>
#include <cstring>
/*
Strings

strings are tied with arrays

strings are groups of characters

we represent text as strings 

we first have to understand chars // will not discuss character encodings
Char: type that has 1 byte of memory
    // allocating memory buffers, 1024 chars is 1 kB
    // doing pointer arithmatic in terms of bytes
    also useful for characters
        ASCII characters are 1 byte : 256 characters
    other encodings are larger than 1 byte though
    UTF16 2^16 characters


font rendering and text are a huge problem

string is an array of chars 
*/


//this function creates a copy of the input arg, of the object
void PrintString(std::string string)
{
    string+="h"; // this would not modify the original string outside the scope
    LOG(string); 
}

//string copy is an expensive task. for read only functions its worth doing
void PrintString_v2(const std::string& string)
{

    LOG(string); 
}

int main(){

//has to be const after C++11
const char * name ="Cherno";  //c style /bp (for some reason I dont get the right memory write, but the variable is interpreted correctly)
// this is const since strings cannot grosw, this is a fixed allocation
// this is not allocated
// name[2]='a'; is not allowed since the above is a const
LOG(name); //bp

//ASCII table .com
// byte at the end is 00 this is the null termination character

//char pointers are  in double quotes ""
// to prove that the null termination character determines length of char array that is passed to stream in cout
const char name2[6]={'c','h','e','r', 'n', 'o'};
//single characters are in single quotes
// without null termination character, the above should have appended at the end
// when:
LOG(name2);

//trash is not there (could this be something related to the architecture?)
// it was related to debug, there where automatic safeguards, the trash does appear without
// null termination

// char name3[7]={'c','h','e','r', 'n', 'o', 0};
const char name3[7]={'c','h','e','r', 'n', 'o', '\0'}; //this now adds the null termination
LOG(name3);

//in c++ there is a class called basic string which is a template class
// std::string is a templated version of basic string/
// string is a template specialization, char is the underlying type

// std::string is what we should be using

std::string name_4 = "cherno_string"; 
//constructor that takes a const char *
LOG(name_4);


//we also have access to a bunch of methods
name_4.size();

//there is a bunch of overloaded operators
name_4+=" hello!";
LOG(name_4);

// a similar thing can be done calling the string constructor
std::string name_5 =std::string("cherno_string")+std::string(" hello!"); 
//sum appends strings
LOG(name_5);

//find text in string

bool contains = name_5.find("no") !=std::string::npos;  //std::string::npos is an illegal position for find
// find returns the postion of the begining of the argument
// reference https://cplusplus.com/reference/string/string/

LOG(contains);
//passing strings to functions
PrintString_v2(name_5);

/*string literals

a series of characters inside double quotes

*/
// "Mendo"; //const char array of size 6, extra character is null termination
const char name_6[7]="Men\0do"; //two null terminations, first one breaks behavior //bp
LOG(name_6);
LOG(strlen(name_6)); //wil give three because of the early termination
//standard c library


//undefined behavior 
// char* name_7 ="mendo"; // not possible, string literals are in a read only section
//                         // of memory, but the above allows to write

// name[1]='a'; //error: c style /bp (for some reason I dont get the right memory write, but the variable is interpreted correctly)

//to modify strings
char name_7[] ="mendo";
LOG(name_7);

//other char sizes (for other encodings)
const char* name_8=u8"mendo";
const char16_t* name_9=u"mendo"; //2 bytes
const char32_t* name_10=U"mendo"; // 4 bytes

//wide could be 2 or 4 bytes depening on compiler
const wchar_t* name_11=L"mendo";

LOG(name_8);
//the three below get poiter values printed with cout
LOG(name_9);
LOG(name_10);
LOG(name_11);

//raw strings to be able to write several lines freely
const char* example =R"(line1
line2
line3)";
LOG(example);

}
