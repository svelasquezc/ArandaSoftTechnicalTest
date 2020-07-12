#ifndef WINDOWS_SYSTEM_INFORMATION_HPP
#define WINDOWS_SYSTEM_INFORMATION_HPP

#include "SystemInformationBase.hpp"

template<class DatabaseHandler>
class WindowsSystemInformation : public SystemInformationBase< WindowsSystemInformation<DatabaseHandler>,  DatabaseHandler > {

private:

    void getInfo();
    
};

#endif /* WINDOWS_SYSTEM_INFORMATION_HPP */
