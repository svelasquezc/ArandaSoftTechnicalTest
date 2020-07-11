#include "SystemInformation.hpp"

template<class DerivedSystemInformation>
DerivedSystemInformation* SystemInformation<DerivedSystemInformation>::derived(){
    return static_cast<DerivedSystemInformation*>(this);
};

template<class DerivedSystemInformation>
template<class DatabaseHandler>
void SystemInformation<DerivedSystemInformation>::info(DatabaseHandler& sql) override{
    derived()->getInfo();
    
};
