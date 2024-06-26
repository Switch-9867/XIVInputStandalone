#include "app.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

INT APIENTRY WinMain(HINSTANCE instance, HINSTANCE, PSTR args, INT cmd_show) {

    cppTemplate::App app{ instance, args, cmd_show };

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}