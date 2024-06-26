#include "keybind.h"

#include "keybind_manager.h"

#include <Windows.h>

namespace xivInputStandalone {

    void Keybind::update()
    {
        isHeldLastFrame = isHeld;
        isHeld = GetAsyncKeyState(sourceKey);

        if (onKeyDown()) sendKeyEvent(false);
        if (onKeyUp()) sendKeyEvent(true);
    }

    void Keybind::simulateKeyPress()
    {
        sendKeyEvent(false); //keydown event
        sendKeyEvent(true); //keyup event
    }

    void Keybind::sendKeyEvent(bool isUp)
    {
        int dwFlags = isUp ? 0x0002 : 0x0000;
        keybd_event(destinationKey, 0, dwFlags, 0);
    }
}