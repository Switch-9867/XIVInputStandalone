#pragma once

#include "keybind.h"
#include "focus_manager.h"

#include <vector>

namespace xivInputStandalone {
    class KeybindManager {
    public:
        KeybindManager(FocusManager* focusManager) : focusManager{ focusManager } {};
        ~KeybindManager();

        KeybindManager(const KeybindManager&) = delete;
        KeybindManager& operator = (const KeybindManager&) = delete;

        void update();
        void createKeybind(int sourceKey, int destinationKey);

        FocusManager* focusManager;

    private:

        bool isEnabled{true};
        std::vector<Keybind> keybinds;
    };
}