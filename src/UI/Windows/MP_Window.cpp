//
// Created by ursbe on 16.09.2023.
//

#include "MP_Window.h"
#include "../../MP/MultiplicativePersistence.h"

MP_Window::MP_Window() {

   data.load();

   highest = data.getNumbers().size();

   window_flags = ImGuiWindowFlags_MenuBar;

}

void MP_Window::update(bool* visible) {

	// For debugging purposes
	visible = reinterpret_cast<bool *>(true);

   ImGui::Begin("Multiplicative Persistence", visible, window_flags);

	// Menu on the top left
   menuBar();

	// Multiplicative Persistence fonction
	if(startMP){
		doMultiplicativePersistence();
	}

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
				data.save();
         }

         if (ImGui::MenuItem("Load", "CTRL+L", false, true)){
				data.load();
         }

			if (ImGui::MenuItem("Start / stop", "CTRL+R", false, true)){
				startMP = !startMP;
			}

         ImGui::EndMenu();
      }

      ImGui::EndMenuBar();
   }
}

void MP_Window::shutdown() {

   data.save();
}

void MP_Window::dataTable() {

   ImGuiTableFlags flags = ImGuiTableFlags_None;

   if(ImGui::BeginTable("table", 3)){

      ImGui::TableSetupColumn("Step", flags);

      ImGui::TableSetupColumn("Number", flags);

      ImGui::TableHeadersRow();

      std::vector<MultiPers> numbers = data.getNumbers();

		// Show the lowest number for each step number
      for(size_t i = 0; i < numbers.size(); i++){
         ImGui::TableNextRow();
			ImGui::TableNextColumn();
         ImGui::Text("%2zu", i + 1);
			ImGui::TableNextColumn();
         ImGui::Text("%20llu", numbers[i]);
      }

      // Show current number being tested
      ImGui::TableNextRow();
		ImGui::TableNextColumn();
      ImGui::Text("Current Number:");
		ImGui::TableNextColumn();
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