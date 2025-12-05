#include "UI/UI.h"
#include <cstdlib>

int main(int argc, char **argv) {

    UI uI;

    if (uI.init("Multiplicative Persistence")) {
        return EXIT_FAILURE;
    }

    while (uI.windowShouldClose()) {
        // Poll events from mouse and keyboard
        uI.pollEvents();

        uI.newFrame();

        uI.Update();

        uI.Render();
    }

    uI.Shutdown();

    return EXIT_SUCCESS;
}


