//
// Created by ursbe on 15.09.2023.
//

#include "UI.h"
#include <stdexcept>
#include "Windows/MainWindow.h"
#include "Windows/MP_Window.h"

int UI::init(const char* windowTitle) {

   if (!glfwInit())
      return 1;

   // Create a GLFW window
   glsl_version = "#version 130";
   _window = glfwCreateWindow(1280, 720, windowTitle, NULL, NULL);
   if (!_window) {
      glfwTerminate();
      return 1;
   }

   glfwMakeContextCurrent(_window);

   glfwGetFramebufferSize(_window, &display_w, &display_h);
   glViewport(0, 0, display_w, display_h);

   IMGUI_CHECKVERSION();

   // Initialize ImGui
   ImGui::CreateContext();

   ImGuiIO& io = ImGui::GetIO(); (void)io;
   io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

   io.Fonts->AddFontDefault();

   ImGui::GetIO().Fonts->AddFontFromFileTTF("./fonts/Roboto/Roboto-Regular.ttf", 24.0f);

   ImGui_ImplGlfw_InitForOpenGL(_window, true);

   ImGui_ImplOpenGL3_Init(glsl_version);

   // Style and preferences
   ImGui::StyleColorsDark();

	adddWindows();

   return 0;
}

bool UI::windowShouldClose() const {
   // Check if window is nullptr
   if(_window == nullptr)
      throw std::runtime_error("Window is nullptr");

   return !glfwWindowShouldClose(_window);
}

void UI::pollEvents() {
   glfwPollEvents();
}

void UI::newFrame() {
   ImGui_ImplOpenGL3_NewFrame();
   ImGui_ImplGlfw_NewFrame();
   ImGui::NewFrame();
}

void UI::Update() {

   ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]);

   // Update all windows
   for(auto& window : windows)
      window->update(reinterpret_cast<bool *>(true));

   ImGui::PopFont();
}

void UI::Render() {
   // Check if window is nullptr
   if(_window == nullptr)
      throw std::runtime_error("Window is nullptr");

   ImGui::Render();
   glClear(GL_COLOR_BUFFER_BIT);
   ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
   glfwSwapBuffers(_window);
}

void UI::Shutdown() {
   // Check if window is nullptr
   if(_window == nullptr)
      throw std::runtime_error("Window is nullptr");

   for(auto& window : windows)
      window->shutdown();

   ImGui_ImplOpenGL3_Shutdown();
   ImGui_ImplGlfw_Shutdown();
   ImGui::DestroyContext();

   glfwDestroyWindow(_window);
   glfwTerminate();
}

UI::~UI() {
   for(auto& window : windows)
      delete window;

}

void UI::adddWindows() {

	// Add main window which is the background of all other windows
	auto* mainWindow = new MainWindow();
	windows.push_back(mainWindow);

	// Add Multiplicative Persistence window
	auto* mpWindow = new MP_Window();
	windows.push_back(mpWindow);
}