#include "SystemInformation.hpp"

#include "LinuxSystemInformation.hpp"
#include "WindowsSystemInformation.hpp"
#include "MacSystemInformation.hpp"


#include <stdexcept>
#include <string>


template<class DatabaseHandler>
class SystemInformationFactory{

public:
    static std::unique_ptr<SystemInformation<DatabaseHandler>> create();
};


template<class DatabaseHandler>
std::unique_ptr<SystemInformation<DatabaseHandler>>
SystemInformationFactory<DatabaseHandler>::create(){
#ifdef __linux__
    return std::make_unique<LinuxSystemInformation<DatabaseHandler>>();
#elif __APPLE__
    return std::make_unique<MacSystemInformation<DatabaseHandler>>();
#elif _WIN32
    return std::make_unique<WindowsSystemInformation<DatabaseHandler>>();
#else
    throw std::runtime_error(std::string("Not implemented in this OS"));
#endif
};
