//
// Created by ursbe on 16.09.2023.
//

#ifndef MULTIPLICATIVEPERSISTENCE_UI_H
#define MULTIPLICATIVEPERSISTENCE_UI_H

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glfw3.h>
#include <vector>
#include "Windows/ImguiWindow.h"

class UI {
public:

    /**
     * Initializes the UI
     * @return
     */
    int init(const char *windowTitle);

    /**
     * Adds all windows used in the program
     */
    void adddWindows();

    /**
     * Checks if the window should close
     * @return true if the window should close
     */
    [[nodiscard]] bool windowShouldClose() const;

    /**
     * Polls the events
     */
    static void pollEvents();

    /**
     * Creates a new frame
     */
    static void newFrame();

    /**
     * Updates the UI
     */
    void Update();

    /**
     * Renders the UI
     */
    void Render();

    /**
     * Shuts down the UI
     */
    void Shutdown();

    ~UI();

private:
    // Main window
    GLFWwindow *_window;

    // OpenGL version
    const char *glsl_version;

    // Display width and height
    int display_w, display_h;

    // All windows
    std::vector<ImguiWindow *> windows;

    // Font available
    bool fontAvailable = false;
};

#endif //MULTIPLICATIVEPERSISTENCE_UI_H