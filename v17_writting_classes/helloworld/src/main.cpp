#include <iostream>


//classes
// write a class and build on it until it is
// considered good

// log class 
// debugging; print status of thing

// logging can be as simple or complicated as we want
// file or network

// ability to write text to the console 
// level of the message 
// what level of log messages we want to send 
// 1 Error
// 2 Warning
// 3 Trace

// if we set to warning, only warnings and errors are shown
// it we set to error only errors are shown
// trace shows everything

class Log{
    // separate the class public variables public methods
    // private variables
    // public static variables ... etc
    // that is why we have multiple public
    public:
        const int LogLevelError=0;
        const int LogLevelWarning=1;
        const int LogLevelInfo=2;

    private:
        int m_Log_level=LogLevelInfo;  // maintins level of log
                          // m_ convention to denote private member variables
                          // local variables wouldnt have this

    public:
    void SetLevel(int level){
        m_Log_level=level;
    }
    void Error(const char* message){
        if(m_Log_level>=LogLevelError)
            std::cout<< "[ERROR]: "<< message<<std::endl;
    }
    void Warn(const char* message){
        if(m_Log_level>=LogLevelWarning)
            std::cout<< "[WARNING]: "<< message<<std::endl;
    }
    void Info(const char* message){
        if(m_Log_level>=LogLevelInfo)
            std::cout<< "[INFO]: "<< message<<std::endl;
    }

};


int main(){
    // way to create an api is by use
    // how might I use that
    // Log log; //parameter initialized
    // log.setLevel(LogLevelWarning);
    // log.Warn("Hello");

    Log log; //parameter initialized
    log.SetLevel(log.LogLevelWarning);
    log.Warn("Hello");
    log.Error("Hello");
    log.Info("Hello"); // doesn't get printed only warnings and above

    
    return 0;

}

//classes are there for ease, only syntactic sugar

