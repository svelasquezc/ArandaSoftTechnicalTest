#ifndef SYSTEM_INFORMATION_BASE_HPP
#define SYSTEM_INFORMATION_BASE_HPP

#include "SystemInformation.hpp"

#include <string>

template<class DerivedSystemInformation, class DatabaseHandler>
class SystemInformationBase : public SystemInformation<DatabaseHandler>{

private:
    
    std::string _processorBrand;
    unsigned int _coresNumber;
    unsigned int _threadsNumber;
    unsigned int _cache;
    unsigned long _totalRam;
    unsigned long _busyRam;
    unsigned long _freeRam;
    unsigned long _sharedRam;
    unsigned long _bufferRam;

    friend DerivedSystemInformation;
    
    //Methods
    DerivedSystemInformation* derived();

public:
    void info() override;
};
#endif /* SYSTEM_INFORMATION_BASE_HPP */
