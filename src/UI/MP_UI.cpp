//
// Created by ursbe on 16.09.2023.
//

#include "MP_UI.h"
#include <imgui.h>
#include "../MP/MultiplicativePersistence.h"

void MP_UI::update() {

   static DataManagement data;
   static MultiPers steps;
   static MultiPers highest = 0;

   ImGui::Begin("Multiplicative Persistence");

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
