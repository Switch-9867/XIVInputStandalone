#pragma once

#include <Windows.h>

#include "keybind_manager.h"
#include "focus_manager.h"

namespace xivInputStandalone {
    class App {
    public:
        App();
        ~App();

        App(const App&) = delete;
        App& operator = (const App&) = delete;

        void run();

    private:

        FocusManager focusManager{};
        KeybindManager keybindManager{ &focusManager };
        bool shouldClose{false};

    };
}