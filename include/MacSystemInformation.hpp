#ifndef MAC_SYSTEM_INFORMATION_HPP
#define MAC_SYSTEM_INFORMATION_HPP

#include "SystemInformationBase.hpp"

template<class DatabaseHandler>
class MacSystemInformation : public SystemInformationBase<MacSystemInformation<DatabaseHandler>, DatabaseHandler>{

private:

    void getInfo();
    
};

#endif /* MAC_SYSTEM_INFORMATION_HPP */
