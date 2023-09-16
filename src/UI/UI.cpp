//
// Created by ursbe on 15.09.2023.
//

#include "UI.h"
#include <stdexcept>
#include "MP_UI.h"

int UI::Init(const char* windowTitle) {

   if (!glfwInit())
      return 1;

   // Create a GLFW window
   glsl_version = "#version 130";
   window = glfwCreateWindow(1280, 720, windowTitle, NULL, NULL);
   if (!window) {
      glfwTerminate();
      return 1;
   }

   glfwMakeContextCurrent(window);

   glfwGetFramebufferSize(window, &display_w, &display_h);
   glViewport(0, 0, display_w, display_h);


   IMGUI_CHECKVERSION();

   // Initialize ImGui
   ImGui::CreateContext();

   ImGuiIO& io = ImGui::GetIO(); (void)io;
   io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

   ImGui_ImplGlfw_InitForOpenGL(window, true);

   ImGui_ImplOpenGL3_Init(glsl_version);

   // Style and preferences
   ImGui::StyleColorsDark();

   return 0;
}

void UI::Update() {

   // Main window which is dockable.
   mainWindow();

   // add your other windows here
   MP_UI::update();
}

void UI::Render() {
   // Check if window is nullptr
   if(window == nullptr)
      throw std::runtime_error("Window is nullptr");

   ImGui::Render();
   glClear(GL_COLOR_BUFFER_BIT);
   ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
   glfwSwapBuffers(window);
}

void UI::Shutdown() {
   // Check if window is nullptr
   if(window == nullptr)
      throw std::runtime_error("Window is nullptr");

   ImGui_ImplOpenGL3_Shutdown();
   ImGui_ImplGlfw_Shutdown();
   ImGui::DestroyContext();

   glfwDestroyWindow(window);
   glfwTerminate();
}

void UI::newFrame() {
   ImGui_ImplOpenGL3_NewFrame();
   ImGui_ImplGlfw_NewFrame();
   ImGui::NewFrame();
}

bool UI::windowShouldClose() const {
   // Check if window is nullptr
   if(window == nullptr)
      throw std::runtime_error("Window is nullptr");

   return !glfwWindowShouldClose(window);
}

void UI::pollEvents() {
   glfwPollEvents();
}

void UI::mainWindow() {

   // Flags for the window
   ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDocking;

   const ImGuiViewport* viewport = ImGui::GetMainViewport();
   ImGui::SetNextWindowPos(viewport->WorkPos);
   ImGui::SetNextWindowSize(viewport->WorkSize);
   ImGui::SetNextWindowViewport(viewport->ID);

   window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
   window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

   ImGui::Begin("Main Docker Window", NULL, window_flags);

   // Submit the DockSpace
   if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DockingEnable)
   {
      ImGuiID dockspace_id = ImGui::GetID("MainDockSpace");
      ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f));
   }

   ImGui::End();
}
