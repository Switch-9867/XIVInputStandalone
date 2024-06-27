#include "keybind_manager.h"

#include "keybind.h"


namespace xivInputStandalone {

    KeybindManager::~KeybindManager()
    {

    }

    void KeybindManager::update()
    {
        if (!isEnabled) return;
        if (keybinds.empty()) return;
        if (!focusManager->shouldEnable) return;

        for (auto& keybind : keybinds) {
            if (keybind.isEnabled) {
                keybind.update();
            }
        }
    }
    void KeybindManager::createKeybind(int sourceKey, int destinationKey)
    {
        auto kb = Keybind::createKeybind();
        kb.sourceKey = sourceKey;
        kb.destinationKey = destinationKey;

        keybinds.push_back(std::move(kb));
    }
}