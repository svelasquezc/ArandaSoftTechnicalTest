#ifndef SYSTEM_INFORMATION_BASE_HPP
#define SYSTEM_INFORMATION_BASE_HPP

#include "SystemInformation.hpp"

#include <string>

template<class DerivedSystemInformation, class DatabaseHandler>
class SystemInformationBase : public SystemInformation<DatabaseHandler>{

private:
    //Processor Info
    std::string _processorBrand;
    unsigned int _coresNumber;
    unsigned int _threadsNumber;

    //RAM info
    unsigned long _totalRam;
    unsigned long _busyRam;
    unsigned long _freeRam;
    
    friend DerivedSystemInformation;
    
    //Methods
    DerivedSystemInformation* derived();

public:
    void info() override;
};

template<class DerivedSystemInformation, class DatabaseHandler>
DerivedSystemInformation* SystemInformationBase<DerivedSystemInformation, DatabaseHandler>::derived(){
    return static_cast<DerivedSystemInformation*>(this);
};

template<class DerivedSystemInformation, class DatabaseHandler>
void SystemInformationBase<DerivedSystemInformation, DatabaseHandler>::info(){
    derived()->getInfo();
    
};

#endif /* SYSTEM_INFORMATION_BASE_HPP */

