//
// Created by ursbe on 18.09.2023.
//

#include "MainWindow.h"
#include "imgui.h"

void MainWindow::update() {

   // Main window which is dockable.
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

void MainWindow::shutdown() {

}
