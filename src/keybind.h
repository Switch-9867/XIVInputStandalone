#pragma once

namespace xivInputStandalone {
    class Keybind {
    public:

        static Keybind createKeybind() {
            return Keybind();
        }

        Keybind(const Keybind&) = delete;
        Keybind& operator = (const Keybind&) = delete;
        Keybind(Keybind&&) = default;
        Keybind& operator = (Keybind&&) = default;

        void update();
        
        bool isEnabled{true};

        bool onKeyDown() { return isHeld && !isHeldLastFrame; }
        bool onKeyUp() { return !isHeld && isHeldLastFrame; }

        void simulateKeyPress();
        void sendKeyEvent(bool isUp = false);

        int sourceKey{0};
        int destinationKey{0};

    private:

        Keybind() {};

        bool isHeld{false};
        bool isHeldLastFrame{false};
    };
}