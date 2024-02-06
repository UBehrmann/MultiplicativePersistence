//
// Created by ursbe on 18.09.2023.
//

#ifndef MULTIPLICATIVEPERSISTENCE_MAINWINDOW_H
#define MULTIPLICATIVEPERSISTENCE_MAINWINDOW_H

#include "ImguiWindow.h"
#include "imgui.h"

#define DOCKSPACE_ID 1 // Waiting for a better solution

class MainWindow : public ImguiWindow {

private:

    ImGuiID dockspaceID;

public:

    MainWindow();

    ~MainWindow() override = default;

    void update(bool *visible) override;

    void shutdown() override;

    [[nodiscard]] ImGuiID getDockspaceID() const {
        return dockspaceID;
    }

};

#endif //MULTIPLICATIVEPERSISTENCE_MAINWINDOW_H