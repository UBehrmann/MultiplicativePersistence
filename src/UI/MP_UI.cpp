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

   ImGui::Text("Current Number: %llu", data.getNumber());
   ImGui::Text("Counter: %llu", highest);

   std::vector<MultiPers> numbers = data.getNumbers();

   for(size_t i = 0; i < numbers.size(); i++){
      ImGui::Text("Step %zu: %llu", i, numbers[i]);
   }


   ImGui::End();

}
