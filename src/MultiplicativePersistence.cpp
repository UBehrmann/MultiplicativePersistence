//
// Created by ursbe on 08.08.2023.
//

#include "MultiplicativePersistence.h"
#include <iostream>
#include <vector>
#include "ConsoleOutput.h"

using namespace std;

MultiPers MultiplicativePersistence(MultiPers number) {

   if( number <= 9){
      return 0;
   }else{
      return 1 + MultiplicativePersistence(addNumber(number));
   }
}

MultiPers addNumber(MultiPers number) {
   MultiPers toReturn = 1;
   string strNumber = to_string(number);

   for (char i : strNumber) {
      toReturn *= static_cast<MultiPers>(i - '0');
   }

   return toReturn;
}

void runMultiplicativePersistence(DataManagement &data) {

   MultiPers steps;
   MultiPers highest = 0;

   do {

      steps = MultiplicativePersistence(data.getNumber());

      if(steps > highest){
         data.addNumber(data.getNumber());
         highest = steps;
      }

      // Update console every X steps
      if(data.getNumber() % UPDATE_CONSOLE_EVERY_X_STEPS == 0) showStage(data.getNumber(), data.getNumbers());

      data.numberAddOne();
   } while (STEP_TO_DO > data.getNumber());


}
