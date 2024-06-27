#include "focus_manager.h"

#include <algorithm>
#include <cctype>

namespace xivInputStandalone {

    FocusManager::FocusManager()
    {

    }

    FocusManager::~FocusManager()
    {

    }

    void FocusManager::update()
    {
        if (validWindowTitles.empty()) return;

        HWND hwnd = GetForegroundWindow();
        std::wstring windowTitle = getWindowTitle(hwnd);

        if (windowTitle == lastTitle) return;
        lastTitle = windowTitle;

        Logger::log("Window Changed: ");
        Logger::log(windowTitle);

        std::transform(windowTitle.begin(), windowTitle.end(), windowTitle.begin(), [](unsigned char c) { return std::tolower(c); });
        
        shouldEnable = false;
        for (auto& inclusion : validWindowTitles) {
            if (windowTitle.find(inclusion) != std::string::npos) {
                shouldEnable = true;
                break;
            }
        }

        if (shouldEnable) {
            Logger::logline(" ENABLED");
        }
        else {
            Logger::logline(" DISABLED");
        }
    }

    std::wstring FocusManager::getWindowTitle(HWND hwnd)
    {
        if (!hwnd) return std::wstring();

        wchar_t title[256];
        int len = GetWindowText(hwnd, title, sizeof(title) / sizeof(title[0]));

        if (len > 0) return std::wstring(title, len);
        return std::wstring();
    }

    void FocusManager::addInclusion(std::wstring inclusion)
    {
        std::wstring lower = inclusion;
        std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c) { return std::tolower(c); });

        Logger::log("Loaded Window Inclusion: \"");
        Logger::log(lower);
        Logger::logline("\"");

        validWindowTitles.push_back(lower);
    }
}