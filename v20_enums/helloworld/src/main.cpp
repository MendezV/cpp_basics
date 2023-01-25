#include <iostream>

//enums in c++
// enumeration, set of values that are valid 
// name to a value (integers )
// way to name values

// integers to represent states

// define a type that can only take a finite number of values

//hover to uncover values
enum Example
{
    A,B,C
};

enum Example2
{
    A=5,B,C
};

enum Example3
{
    A=2,B=4,C=7
};

enum Example4 : char //8 bit char instead of 32 bit integer
{
    A,B,C
};

//real world example

class Log{

    public:
    enum Level
    {
        LevelError=0,LevelWarning,LevelInfo
    };
    
    private:
        Level m_Log_level=LevelInfo;  // define as the enum so it can only take the values above
    
    public:
    void SetLevel(Level level){
        m_Log_level=level;
    }
    void Error(const char* message){
        if(m_Log_level>=LevelError)
            std::cout<< "[ERROR]: "<< message<<std::endl;
    }
    void Warn(const char* message){
        if(m_Log_level>=LevelWarning)
            std::cout<< "[WARNING]: "<< message<<std::endl;
    }
    void Info(const char* message){
        if(m_Log_level>=LevelInfo)
            std::cout<< "[INFO]: "<< message<<std::endl;
    }

};


int main(){


    Log log; //parameter initialized
    log.SetLevel(Log::LevelError);
    log.Warn("Hello");
    log.Error("Hello");
    log.Info("Hello"); // doesn't get printed only warnings and above

    
    return 0;

}

//enum classes in another video

