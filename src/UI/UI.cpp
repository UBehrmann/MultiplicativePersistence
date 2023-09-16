//
// Created by ursbe on 15.09.2023.
//

#include "UI.h"
#include <stdexcept>

int UI::Init() {

   if (!glfwInit())
      return 1;

   // Create a GLFW window
   glsl_version = "#version 130";
   window = glfwCreateWindow(1280, 720, "ImGui Example", NULL, NULL);
   if (!window) {
      glfwTerminate();
      return 1;
   }

   glfwMakeContextCurrent(window);

   glfwGetFramebufferSize(window, &display_w, &display_h);
   glViewport(0, 0, display_w, display_h);

   IMGUI_CHECKVERSION();

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

   // Main windiw which is dockable.
   mainWindow();

   anotherWindow();
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

void UI::anotherWindow() {
   ImGui::Begin("Hello, world!");
   ImGui::Text("Input a string:");
   // Input buffer
   static char buf[256] = "";
   ImGui::InputText(" ", buf, 256);
   ImGui::Text("You wrote: %s", buf);

   static unsigned int counter = 0;

   ImGui::Text("Counter: %d", counter);

   counter++;

   ImGui::End();
}

void UI::mainWindow() {
   static bool* p_open = new bool(true);

   static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

   ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;

   const ImGuiViewport* viewport = ImGui::GetMainViewport();
   ImGui::SetNextWindowPos(viewport->WorkPos);
   ImGui::SetNextWindowSize(viewport->WorkSize);
   ImGui::SetNextWindowViewport(viewport->ID);
   ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
   ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
   window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
   window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

   // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
   // and handle the pass-thru hole, so we ask Begin() to not render a background.
   if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
      window_flags |= ImGuiWindowFlags_NoBackground;

   ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

   ImGui::Begin("DockSpace Demo", p_open, window_flags);

   ImGui::PopStyleVar();

   ImGui::PopStyleVar(2);

   // Submit the DockSpace
   ImGuiIO& io = ImGui::GetIO();
   if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
   {
      ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
      ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
   }


   if (ImGui::BeginMenuBar())
   {
      if (ImGui::BeginMenu("Options"))
      {
         // Menu Bar Options

         ImGui::EndMenu();
      }

      ImGui::EndMenuBar();
   }

   ImGui::End();
}
