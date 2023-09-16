//
// Created by ursbe on 16.09.2023.
//

#ifndef MULTIPLICATIVEPERSISTENCE_UI_H
#define MULTIPLICATIVEPERSISTENCE_UI_H

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glfw3.h>

class UI {
public:

   /**
    * Initializes the UI
    * @return
    */
   int Init(const char* windowTitle);

   /**
    * Polls the events
    */
   void pollEvents();

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

   /**
    * Creates a new frame
    */
   void newFrame();

   /**
    * Checks if the window should close
    * @return true if the window should close
    */
   [[nodiscard]] bool windowShouldClose() const;

   /**
    * Creates the main window
    */
   void mainWindow();

private:
   // Main window
   GLFWwindow* window;

   // OpenGL version
   const char* glsl_version;

   // Display width and height
   int display_w, display_h;

};

#endif //MULTIPLICATIVEPERSISTENCE_UI_H
