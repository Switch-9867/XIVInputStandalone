#pragma once

#include <Windows.h>

#include "keybind_manager.h"

namespace xivInputStandalone {
    class App {
    public:
        App();
        ~App();

        App(const App&) = delete;
        App& operator = (const App&) = delete;

        void run();

    private:

        KeybindManager keybindManager{};
        bool shouldClose;

    };
}