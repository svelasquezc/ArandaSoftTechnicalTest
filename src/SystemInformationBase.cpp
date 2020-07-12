#include "SystemInformationBase.hpp"

template<class DerivedSystemInformation, class DatabaseHandler>
DerivedSystemInformation* SystemInformationBase<DerivedSystemInformation, DatabaseHandler>::derived(){
    return static_cast<DerivedSystemInformation*>(this);
};

template<class DerivedSystemInformation, class DatabaseHandler>
void SystemInformationBase<DerivedSystemInformation, DatabaseHandler>::info(){
    derived()->getInfo();
    
};
