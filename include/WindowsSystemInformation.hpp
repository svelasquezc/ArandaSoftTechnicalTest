#ifndef WINDOWS_SYSTEM_INFORMATION_HPP
#define WINDOWS_SYSTEM_INFORMATION_HPP

#include "SystemInformationBase.hpp"

template<class DatabaseHandler>
class WindowsSystemInformation : public SystemInformationBase< WindowsSystemInformation<DatabaseHandler>,  DatabaseHandler > {

private:

    void getInfo();
    friend SystemInformationBase<LinuxSystemInformation<DatabaseHandler>, DatabaseHandler>;
};

//Taken from: https://docs.microsoft.com/en-us/windows/win32/sysinfo/getting-hardware-information?redirectedfrom=MSDN
#ifdef _WIN32

#include <windows.h>
#pragma comment(lib, "user32.lib")

template<class DatabaseHandler>
void WindowsSystemInformation<DatabaseHandler>::getInfo(){
    SYSTEM_INFO processor_info;

    GetSystemInfo(&processor_info);

    this->_coresNumber = processor_info.dwNumberOfProcessors;
    
    this->_threadsNumber = static_cast<unsigned int>(std::thread::hardware_concurrency());

    this->_processorBrand = std::string(static_cast<const char*>(processor_info.dwProcessorType));

    //Taken from: https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex

    MEMORYSTATUSEX memory_info;

    GlobalMemoryStatusEx(&memory_info);

    this->_totalRam = ((unsigned long long) memory_info.ullTotalPhys)/1024;
    this->_freeRam  = ((unsigned long long) memory_info.ullAvailPhys)/1024;
    this->_busyRam  = this->_totalRam - this->_freeRam;
};


#endif /* _WIN32 */
#endif /* WINDOWS_SYSTEM_INFORMATION_HPP */
