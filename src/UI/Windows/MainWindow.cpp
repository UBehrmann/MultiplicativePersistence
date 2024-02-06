//
// Created by ursbe on 18.09.2023.
//

#include "MainWindow.h"
#include "imgui.h"

using namespace ImGui;


void MainWindow::update(bool *visible) {

    // Always show this window
    visible = reinterpret_cast<bool *>(true);

    // Main window which is dockable.
    // Flags for the window
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDocking |
                                    ImGuiWindowFlags_NoTitleBar |
                                    ImGuiWindowFlags_NoCollapse |
                                    ImGuiWindowFlags_NoResize |
                                    ImGuiWindowFlags_NoMove |
                                    ImGuiWindowFlags_NoBringToFrontOnFocus |
                                    ImGuiWindowFlags_NoNavFocus;

    const ImGuiViewport *viewport = GetMainViewport();

    SetNextWindowPos(viewport->WorkPos);
    SetNextWindowSize(viewport->WorkSize);
    SetNextWindowViewport(viewport->ID);

    Begin("Main Docker Window", visible, window_flags);

    // Submit the DockSpace
    if (GetIO().ConfigFlags & ImGuiConfigFlags_DockingEnable) {
        DockSpace(DOCKSPACE_ID, ImVec2(0.0f, 0.0f));
    }

    End();
}

void MainWindow::shutdown() {

}

MainWindow::MainWindow() {
    dockspaceID = DOCKSPACE_ID;
}
