#pragma once

#include "keybind.h"

#include <vector>

namespace xivInputStandalone {
    class KeybindManager {
    public:
        KeybindManager();
        ~KeybindManager();

        KeybindManager(const KeybindManager&) = delete;
        KeybindManager& operator = (const KeybindManager&) = delete;

        void update();
        void createKeybind(int sourceKey, int destinationKey);

    private:

        bool isEnabled{true};
        std::vector<Keybind> keybinds;
    };
}