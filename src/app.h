#pragma once

#include <Windows.h>

namespace cppTemplate {
    class App {
    public:
        App(HINSTANCE instance, PSTR args, INT cmd_show);
        ~App();

        App(const App&) = delete;
        App& operator = (const App&) = delete;

        void run();

    private:

    };
}