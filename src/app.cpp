#include "app.h"

namespace xivInputStandalone {

    App::App()
    {
        
    }

    App::~App()
    {
        
    }

    void App::run()
    {
        // add defaults
        keybindManager.createKeybind(VK_XBUTTON1, VK_LSHIFT);
        keybindManager.createKeybind(VK_XBUTTON2, VK_LCONTROL);

        while (!shouldClose) {
            keybindManager.update();
        }
    }

}