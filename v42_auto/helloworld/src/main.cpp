#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

/*
auto

automatically deducing types
return types can be automated

lends itself to good or bad things
 
auto is very simple, probably we shouldnt 
go overboard
*/

const char* GetName()
{
    return "cherno";
}

class Device
{

};

class DeviceManager
{
    private:
        std::unordered_map<std::string, std::vector<Device*>> m_devices; //map from strings to devices
    public:
    const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
    {
        return m_devices;
    }
};  
int main()
{
    // int a =5;
    // auto b=a;
    // auto c = 4;
    // auto d = 4.4;
    // auto st="cherno";


    //kind of turn on a weakly typed languate
    // only write auto everywhere

    //lends itself to two things
    //auto everywhere? a matter of style
    // benefits and setbacks


    //how to use auto

    std::string name = GetName(); //this works because of the implicit constructor that takes char*
    std::cout<< name << std::endl; //but in case it didn't we would have to change 
                                    //the code here as well when we change the return value 
                                    //of the function

    auto name2 = GetName(); //updating the type of the function is seemless here
    std::cout<< name2 << std::endl;

    // on the one hand makes changes to the API seemless
    // on the other, this implies that if my code relied
    // on the specific type of variable, things might break
    // without me noticing


    // these cases do not warrant the use of auto
    

    //case in which is useful
    std::vector<std::string> stringo;
    stringo.push_back("apple");
    stringo.push_back("orange");

    for (std::vector<std::string>::iterator it =stringo.begin(); it!= stringo.end(); it++)
        std::cout<<*it<<std::endl;

    //probably for each or range based loop

    //but managing the typpe gives
    for (auto it =stringo.begin(); it!= stringo.end(); it++)
        std::cout<<*it<<std::endl;

    DeviceManager dm;
    const std::unordered_map<std::string, std::vector<Device*>>& 
            devices=dm.GetDevices();

    
    // one solution
    using DeviceMap=std::unordered_map<std::string, std::vector<Device*>>;
    
    const DeviceMap& devices2=dm.GetDevices();

    //alternatively supporting all code bases
    typedef std::unordered_map<std::string, std::vector<Device*>>  DeviceMapy;

    const DeviceMapy& devices3=dm.GetDevices();

    //type is a lot easier. we can move the typedef or using to the class itself

    // good case for auto if the type is too long
    // if the type is ambiguous like in a complicated template
    // then its probably not a good idea
}   
