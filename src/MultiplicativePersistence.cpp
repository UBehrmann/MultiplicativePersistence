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

void runMultiplicativePersistence() {

   vector<MultiPers> numbers;

   MultiPers number = 1; // 277777788888899; // 277 777 788 888 899 11 steps
   MultiPers steps;
   MultiPers highest = 0;

   do {

      steps = MultiplicativePersistence(number);

      if(steps > highest){
         numbers.push_back(number);
         highest = steps;
      }

      // Update console every X steps
      if(number % UPDATE_CONSOLE_EVERY_X_STEPS == 0) showStage(number, numbers);

      number++;
   } while (STEP_TO_DO > number);


}
