#ifndef MAC_SYSTEM_INFORMATION_HPP
#define MAC_SYSTEM_INFORMATION_HPP

#include "SystemInformationBase.hpp"

template<class DatabaseHandler>
class MacSystemInformation : public SystemInformationBase<MacSystemInformation<DatabaseHandler>, DatabaseHandler>{

private:

    void getInfo();
    friend SystemInformationBase<LinuxSystemInformation<DatabaseHandler>, DatabaseHandler>;
};

#ifdef __APPLE__

#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <string>

template<class DatabaseHandler>
void MacSystemInformation<DatabaseHandler>::getInfo(){

    //Taken from: https://stackoverflow.com/questions/853798/programmatically-get-processor-details-from-mac-os-x
    
    char buffer[1024];
    size_t size=sizeof(buffer);
    if (sysctlbyname("machdep.cpu.brand_string", &buffer, &size, NULL, 0) < 0) {
        perror("sysctl");
    };
    
    this->_processorBrand = std::string(buffer);

    size = sizeof(this->_coresNumber);
    
    if (sysctlbyname("hw.ncpu", &(this->_coresNumber), &size, NULL, 0) < 0) {
        perror("sysctl");
    };
};

#endif /* __APPLE__ */

#endif /* MAC_SYSTEM_INFORMATION_HPP */
