//
// Created by ursbe on 16.09.2023.
//

#include "MP_UI.h"
#include <imgui.h>
#include "../MP/MultiplicativePersistence.h"

void MP_UI::update() {

   // Flags for the window
   ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar;

   static DataManagement data;
   static MultiPers steps;
   static MultiPers highest = 0;

   ImGui::Begin("Multiplicative Persistence", nullptr, window_flags);

   menuBar();

   steps = MultiplicativePersistence(data.getNumber());

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

void MP_UI::menuBar() {
   if (ImGui::BeginMenuBar())
   {
      if (ImGui::BeginMenu("Options"))
      {
         // Menu Bar Options

         if (ImGui::MenuItem("Save", "CTRL+S", false, true)){
            // TODO: Save to file
         }

         ImGui::EndMenu();
      }

      ImGui::EndMenuBar();
   }
}
