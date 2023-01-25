#include <iostream>
#include <cmath>
/*
casting

mostly a practical skill

conversion within the type system
c++ is a strongly typed language and types are enforced
easy implicit conversion? 
explicit conversion?

c style cast
*/

int main(){

    double a=5.3;
    std::cout<< "positive double"<<std::endl;
    std::cout<< (int)a<<std::endl;
    std::cout<< (int)ceil(a)<<std::endl;
    std::cout<< (int)floor(a)<<std::endl;


    a=-5.3;
    std::cout<< "negative double"<<std::endl;
    std::cout<< (int)a<<std::endl;
    std::cout<< (int)ceil(a)<<std::endl;
    std::cout<< (int)floor(a)<<std::endl;

    a=-0.00000000000000000000000000001;
    std::cout<< "negative double"<<std::endl;
    std::cout<< (int)a<<std::endl;
    std::cout<< (int)ceil(a)<<std::endl;
    std::cout<< (int)floor(a)<<std::endl;


}