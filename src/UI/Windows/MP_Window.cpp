//
// Created by ursbe on 16.09.2023.
//

#include "MP_Window.h"
#include "imgui.h"
#include "../../MP/MultiplicativePersistence.h"

void MP_Window::update() {

   // Flags for the window
   ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar;

   ImGui::Begin("Multiplicative Persistence", nullptr, window_flags);

   menuBar();

   MultiPers steps = MultiplicativePersistence(data.getNumber());

   if(steps > highest){
      data.addNumber(data.getNumber());
      highest = steps;
   }

   data.numberAddOne();

   std::vector<MultiPers> numbers = data.getNumbers();

   // Show lowest number for each step
   for(size_t i = 0; i < numbers.size(); i++){
      ImGui::Text("Step %2zu:         %20llu", i + 1, numbers[i]);
   }

   // Show current number being tested
   ImGui::Text("Current Number:  %20llu", data.getNumber());

   ImGui::End();
}

void MP_Window::menuBar() {
   if (ImGui::BeginMenuBar())
   {
      if (ImGui::BeginMenu("Options"))
      {
         // Menu Bar Options

         if (ImGui::MenuItem("Save", "CTRL+S", false, true)){
            // TODO: Save to file
         }

         if (ImGui::MenuItem("Load", "CTRL+L", false, true)){
            // TODO: Load from file
         }

         ImGui::EndMenu();
      }

      ImGui::EndMenuBar();
   }
}

MP_Window::MP_Window() {

   data.loadFromFile();

   highest = data.getNumbers().size();
}

void MP_Window::shutdown() {

   data.saveToFile();
}