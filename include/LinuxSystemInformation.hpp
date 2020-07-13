#ifndef LINUX_SYSTEM_INFORMATION_HPP
#define LINUX_SYSTEM_INFORMATION_HPP

#include "SystemInformationBase.hpp"

template<class DatabaseHandler>
class LinuxSystemInformation : public SystemInformationBase<LinuxSystemInformation<DatabaseHandler>, DatabaseHandler>{

private:

    void getInfo();
    friend SystemInformationBase<LinuxSystemInformation<DatabaseHandler>, DatabaseHandler>;
};


#ifdef __linux__
#include <unistd.h>
#include <cpuid.h>
#include <thread>
#include <sys/sysinfo.h>

//Taken from https://stackoverflow.com/questions/6491566/getting-the-machine-serial-number-and-cpu-id-using-c-c-in-linux

struct CPUVendorID {
    unsigned int ebx;
    unsigned int edx;
    unsigned int ecx;

    std::string toString() const {
        return std::string(reinterpret_cast<const char *>(this), 12);
    }
};

template<class DatabaseHandler>
void LinuxSystemInformation<DatabaseHandler>::getInfo(){

    this->_coresNumber = sysconf(_SC_NPROCESSORS_CONF);

    //Taken from https://stackoverflow.com/questions/6491566/getting-the-machine-serial-number-and-cpu-id-using-c-c-in-linux
    
    {
        unsigned int level = 0;
        unsigned int eax = 0;
        unsigned int ebx;
        unsigned int ecx;
        unsigned int edx;

        __get_cpuid(level, &eax, &ebx, &ecx, &edx);

        CPUVendorID vendorID { .ebx = ebx, .edx = edx, .ecx = ecx };

        this->_processorBrand = vendorID.toString();
    };

    this->_threadsNumber = static_cast<unsigned int>(std::thread::hardware_concurrency());

    //Taken from: https://stackoverflow.com/questions/43481494/total-ram-size-linux-sysinfo-vs-proc-meminfo
    
    struct sysinfo memory_info;

    this->_totalRam  = ((unsigned long long) memory_info.totalram * memory_info.mem_unit)/1024;
    this->_freeRam   = ((unsigned long long) memory_info.freeram * memory_info.mem_unit)/1024;
    this->_busyRam   = this->_totalRam - this->_freeRam; 
    
};
#else
#include <stdexcept>
#include <string>
template<class DatabaseHandler>
void LinuxSystemInformation<DatabaseHandler>::getInfo(){
    throw std::runtime_error(std::string("Not implemented in this OS"));
};
#endif /* __linux__ */


#endif /* LINUX_SYSTEM_INFORMATION_HPP */
