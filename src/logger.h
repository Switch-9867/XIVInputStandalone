#pragma once

#include <string>

namespace xivInputStandalone {
    class Logger {
    public:
        Logger();
        ~Logger();

        Logger(const Logger&) = delete;
        Logger& operator = (const Logger&) = delete;

        static void log(std::string msg);
        static void log(std::wstring msg);
        static void logline(std::string msg);
        static void logline(std::wstring msg);

    private:
    };
}