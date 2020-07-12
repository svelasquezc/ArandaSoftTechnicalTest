#ifndef LINUX_SYSTEM_INFORMATION_HPP
#define LINUX_SYSTEM_INFORMATION_HPP

#include "SystemInformationBase.hpp"

template<class DatabaseHandler>
class LinuxSystemInformation : public SystemInformationBase<LinuxSystemInformation<DatabaseHandler>, DatabaseHandler>{

private:

    void getInfo();
    
};

#endif /* LINUX_SYSTEM_INFORMATION_HPP */
