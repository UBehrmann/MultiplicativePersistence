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

   int Init();
   void pollEvents();
   virtual void Update();
   void Render();
   void Shutdown();
   void newFrame();
   [[nodiscard]] bool windowShouldClose() const;

   void mainWindow();

   void anotherWindow();

private:
   GLFWwindow* window;
   const char* glsl_version;
   int display_w, display_h;

};


#endif //MULTIPLICATIVEPERSISTENCE_UI_H
