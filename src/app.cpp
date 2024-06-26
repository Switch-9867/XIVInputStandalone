#include "app.h"

#include <chrono>
#include <thread>

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
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

}