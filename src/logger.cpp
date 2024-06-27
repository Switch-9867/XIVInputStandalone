#include "logger.h"
#include <iostream>

namespace xivInputStandalone {

    Logger::Logger()
    {

    }

    Logger::~Logger()
    {

    }

    void Logger::log(std::string msg)
    {
        std::cout << msg;
    }

    void Logger::log(std::wstring msg)
    {
        std::wcout << msg;
    }

    void Logger::logline(std::string msg)
    {
        std::cout << msg << std::endl;
    }
    void Logger::logline(std::wstring msg)
    {
        std::wcout << msg << std::endl;
    }
}