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

#endif /* SYSTEM_INFORMATION_HPP */
