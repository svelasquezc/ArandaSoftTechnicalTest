#ifndef SYSTEM_INFORMATION_HPP
#define SYSTEM_INFORMATION_HPP

#include <memory>
template<class DatabaseHandler>
class SystemInformation{
private:

    std::shared_ptr<DatabaseHandler> dbmanager;
    
public:
    
    virtual void info() = 0;
};
template<class DatabaseHandler>
std::unique_ptr<SystemInformation<DatabaseHandler>> makeSystemInformation();

#endif /* SYSTEM_INFORMATION_HPP */
