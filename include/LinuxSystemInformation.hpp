#ifndef LINUX_SYSTEM_INFORMATION_HPP
#define LINUX_SYSTEM_INFORMATION_HPP

#include "SystemInformation.hpp"

class LinuxSystemInformation : public SystemInformation<LinuxSystemInformation>{

private:

    void getInfo() override;
    
};

#endif /* LINUX_SYSTEM_INFORMATION_HPP */
