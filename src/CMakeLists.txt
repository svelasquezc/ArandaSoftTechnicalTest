target_sources(${PROJECT_NAME} PUBLIC main.cpp)

target_sources(OSSysInfo PRIVATE
  SystemInformation.cpp
  SystemInformationBase.cpp
  LinuxSystemInformation.cpp)
