//
// Created by ursbe on 16.09.2023.
//

#include "MP_Window.h"
#include "../../MP/MultiplicativePersistence.h"

MP_Window::MP_Window() {

   data.loadFromFile();

   highest = data.getNumbers().size();

   window_flags = ImGuiWindowFlags_MenuBar;

}

void MP_Window::update() {

   ImGui::Begin("Multiplicative Persistence", nullptr, window_flags);

   menuBar();

   doMultiplicativePersistence();

   dataTable();

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

void MP_Window::shutdown() {

   data.saveToFile();
}

void MP_Window::dataTable() {

   ImGuiTableFlags flags = ImGuiTableFlags_None;

   if(ImGui::BeginTable("table", 3)){
      ImGui::TableSetupColumn("Step", flags);

      ImGui::TableSetupColumn("Number", flags);

      ImGui::TableHeadersRow();

      std::vector<MultiPers> numbers = data.getNumbers();

      for(size_t i = 0; i < numbers.size(); i++){
         ImGui::TableNextRow();
         ImGui::TableSetColumnIndex(0);
         ImGui::Text("%2zu", i + 1);
         ImGui::TableSetColumnIndex(1);
         ImGui::Text("%20llu", numbers[i]);
      }

      // Show current number being tested
      ImGui::TableNextRow();
      ImGui::TableSetColumnIndex(0);
      ImGui::Text("Current Number:");
      ImGui::TableSetColumnIndex(1);
      ImGui::Text("%20llu", data.getNumber());

      ImGui::EndTable();
   }
}

void MP_Window::doMultiplicativePersistence() {

   MultiPers steps = MultiplicativePersistence(data.getNumber());

   if(steps > highest){
      data.addNumber(data.getNumber());
      highest = steps;
   }

   data.numberAddOne();
}