#pragma once

#include "logger.h"

#include <vector>
#include <string>
#include <Windows.h>

namespace xivInputStandalone {
    class FocusManager {
    public:
        FocusManager();
        ~FocusManager();

        FocusManager(const FocusManager&) = delete;
        FocusManager& operator = (const FocusManager&) = delete;

        void update();
        std::wstring getWindowTitle(HWND hwnd);
        void addInclusion(std::wstring windowTitle);
        bool shouldEnable{false};

    private:

        std::wstring lastTitle;
        std::vector<std::wstring> validWindowTitles;

    };
}