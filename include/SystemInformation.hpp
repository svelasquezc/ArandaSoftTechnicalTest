#ifndef SYSTEM_INFORMATION_HPP
#define SYSTEM_INFORMATION_HPP

#include "SystemInformationInterface.hpp"

#include <string>

template<class DerivedSystemInformation>
class SystemInformation : public SystemInformationInterface{

private:
    
    std::string _processorName;
    unsigned int _coresNumber;
    unsigned int _threadsNumber;
    unsigned int _cache;
    unsigned long _totalRam;
    unsigned long _freeRam;
    unsigned long _sharedRam;
    unsigned long _bufferRam;

    
    
    friend class DerivedSystemInformation;


    //Methods
    SystemInformation(){};
    const DerivedSystemInformation* derived();
    virtual void getInfo() = 0;

public:
    template<class DatabaseHandler>
    void info(DatabaseHandler& sql) override;
};
#endif /* SYSTEM_INFORMATION_HPP */
