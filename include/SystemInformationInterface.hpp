#ifndef SYSTEM_INFORMATION_INTERFACE_HPP
#define SYSTEM_INFORMATION_INTERFACE_HPP

class SystemInformationInterface{
public:
    template<class DatabaseHandler>
    virtual void info(DatabaseHandler& sql) = 0;
};

#endif /* SYSTEM_INFORMATION_INTERFACE_HPP */
