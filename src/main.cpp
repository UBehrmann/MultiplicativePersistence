#include <iostream>
#include <string>
#include "MultiplicativePersistence.h"

using namespace std;

#define STEP_TO_DO ULLONG_MAX \
// 18'446'744'073'709'551'615
//        277'777'788'888'899

int main() {

   MultiPers number = 1; // 277777788888899; // 277 777 788 888 899 11 steps
   MultiPers steps = 0;
   MultiPers nbOfSteps = 0;
   MultiPers highest = 0;
   MultiPers highestNumber = 0;

   do {

      steps = MultiplicativePersistence(number);

      if(steps > highest){
         cout << "Number : " << number << " Steps : " << steps << endl;
         highest = steps;
         highestNumber = number;
      }

      number++;
   } while (STEP_TO_DO > number);

   return 0;
}


